%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern Node *g_root; // A way of getting the AST out


  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  extern int yylex(void);
  extern int yyparse();
  extern FILE *yyin;
  void yyerror(const char *);
}

%union{
  Node *expr;
  double number;
  std::string *string;
}

%token T_WHILE T_FOR T_IF T_ELSE T_INT T_VOID T_ENUM T_RETURN T_BREAK T_CONTINUE T_SWITCH T_CASE T_DEFAULT GOTO T_DO
%token T_ADDEQUAL T_DIVIDEEQUAL T_MODEQUAL T_SUBEQUAL T_MULTEQUAL T_LEFTEQUAL T_RIGHTEQUAL T_ANDEQUAL T_XOREQUAL T_OREQUAL
%token T_SHIFTRIGHT T_SHIFTLEFT T_LESSTHAN T_GREATERTHAN T_GREATERTHANEQUAL T_LESSTHANEQUAL T_STRUCT T_UNION
%token T_OR T_AND T_NOT T_MODULO T_EQUAL T_ASSIGN T_NOTEQUAL T_INVERT T_AND_OP T_OR_OP T_CONST T_VOLATILE
%token T_MULTIPLY T_DIV T_ADD T_SUB T_XOR INC_OP DEC_OP T_EXTERN T_TYPEDEF T_STATIC T_ELLIPSIS
%token T_LBRACKET T_RBRACKET L_SQRBRACKET R_SQRBRACKET T_LCURLY T_RCURLY T_SEMICOLON T_COMMA T_COLON T_QUESTION T_PERIOD
%token T_UNSIGNED T_CHAR T_SIZEOF T_FLOAT T_DOUBLE
%token T_NUM T_VARIABLE T_CHARVAL

%type <expr> TYPE_SPE DECLARATION PRIM_EXPR POSTFIX_EXPR UNARY_EXPR CAST_EXPR MULT_EXPR ADD_EXPR EQUAL_EXPR AND_EXPR INCLUSIVE_OR_EXPR ASSIGN_EXPR EXPR LOGIC_AND_EXPR VARIABLE_STORE_LIST VARIABLE_STORE XOR_EXPR
%type <expr> DECLARATOR DIRECT_DECL T_VARIABLE_LIST STATEMENT LABELED_STATEMENT COMPOUND_STATEMENT DECLARATION_LIST EXPR_STATEMENT SELECT_STATEMENT ITERATION_STATEMENT FUNCT_DEF SHIFT_EXPR COMPARISON_EXPR
%type <expr> LOGIC_OR_EXPR INITIALISE_DECLARATOR_LIST INITIALISE_DECLARATOR DECLARATION_SPE ENUMERATOR ENUM_LIST ENUM_SPECIFIER JUMP_STATEMENT CONDITION_EXPR CONST_EXPR
%type <expr> PARAM_LIST PARAM_TYPE_LIST PARAM_DECLARATION ARG_EXPR_LIST EXTERN_DECL TRANSLATION_UNIT STATEMENT_LIST ABS_DECLARATOR DIRECT_ABS_DECLARATOR POINTER TYPE_NAME SPE_QUALIFIER_LIST
%type <expr> TYPE_QUALIFIER TYPE_QUALIFIER_LIST STRUCT_DECLARATOR STRUCT_DECLARATOR_LIST STRUCT_DECLARATION STRUCT_DECLARATION_LIST STRUCT_OR_UNION STRUCT_OR_UNION_SPE
%type <number> T_NUM
%type <string> T_IF T_ELSE T_WHILE T_FOR T_ASSIGN T_ADDEQUAL T_DIVIDEEQUAL T_MODEQUAL T_SUBEQUAL T_MULTEQUAL T_LEFTEQUAL T_RIGHTEQUAL T_ANDEQUAL T_XOREQUAL T_OREQUAL T_DOUBLE
%type <string> T_VARIABLE ASSIGN_OP UNARY_OP T_INT T_RETURN T_AND T_ADD T_MULTIPLY T_SUB T_INVERT T_NOT INC_OP DEC_OP GOTO T_DO T_STRUCT T_UNION T_CHAR T_UNSIGNED T_VOID T_FLOAT T_SIZEOF T_CHARVAL

%start ROOT

%%
PRIM_EXPR: T_VARIABLE { $$ = new VariableName(*$1);}
          | T_NUM { $$ = new Number($1);}
          | T_CHARVAL { $$ = new CharName(*$1);}
          | T_LBRACKET EXPR T_RBRACKET { $$ = $2;}
          ;

POSTFIX_EXPR: PRIM_EXPR { $$ = $1;}
            | POSTFIX_EXPR L_SQRBRACKET EXPR R_SQRBRACKET { $$ = new array_identifier($1,$3);}
            | POSTFIX_EXPR T_LBRACKET T_RBRACKET { $$ = new function_decl($1);} //check later
            | POSTFIX_EXPR T_LBRACKET ARG_EXPR_LIST T_RBRACKET {$$ = new function_decl($1,$3);}
            | POSTFIX_EXPR T_PERIOD T_VARIABLE 
            | UNARY_EXPR INC_OP { $$ = new unaryExpr($1,*$2);}
            | UNARY_EXPR DEC_OP{ $$ = new unaryExpr($1,*$2);}
            ;


ARG_EXPR_LIST : ASSIGN_EXPR { $$ = new Variable($1);}
                | ASSIGN_EXPR T_COMMA ARG_EXPR_LIST { $$ = new param_list(new Variable($1),$3);}
             ;

UNARY_EXPR: POSTFIX_EXPR{ $$ = $1;}
            | UNARY_OP CAST_EXPR { $$ = new unaryOp(*$1,$2);}
            | INC_OP UNARY_EXPR { $$ = new unaryExpr(*$1,$2);}
            | DEC_OP UNARY_EXPR { $$ = new unaryExpr(*$1,$2);}
            | T_SIZEOF UNARY_EXPR {$$ = new sizeofsmtg{$2};}
            | T_SIZEOF T_LBRACKET PRIM_EXPR T_RBRACKET {$$ = new sizeofsmtg{$3};}
            |T_SIZEOF T_LBRACKET TYPE_SPE T_RBRACKET {$$ = new sizeofsmtg{$3};}
            ;

UNARY_OP: T_AND { $$ = $1;}
          | T_MULTIPLY { $$ = $1;}
          | T_ADD { $$ = $1;}
          | T_SUB { $$ = $1; }
          | T_INVERT { $$ = $1;}
          | T_NOT { $$ = $1;}
          ;

CAST_EXPR: UNARY_EXPR { $$ = $1;}
          ;

MULT_EXPR: CAST_EXPR { $$ = $1;}
          | MULT_EXPR T_MULTIPLY CAST_EXPR { $$ = new multOp($1,$3);}
          | MULT_EXPR T_DIV CAST_EXPR { $$ = new divOp($1,$3);}
          | MULT_EXPR T_MODULO CAST_EXPR { $$ = new modOp($1,$3);}
          ;

ADD_EXPR: MULT_EXPR { $$ = $1;}
        | ADD_EXPR T_ADD MULT_EXPR { $$ = new addOp($1,$3);}
        | ADD_EXPR T_SUB MULT_EXPR { $$ = new subOp($1,$3);}
        ;

SHIFT_EXPR: ADD_EXPR { $$ = $1;}
          | SHIFT_EXPR T_SHIFTLEFT ADD_EXPR { $$ = new leftShiftOp($1,$3);}
          | SHIFT_EXPR T_SHIFTRIGHT ADD_EXPR { $$ = new rightShiftOp($1,$3);}
          ;

COMPARISON_EXPR: SHIFT_EXPR { $$ = $1;}
          | COMPARISON_EXPR T_LESSTHAN SHIFT_EXPR { $$ = new lessThan($1, $3);}
          | COMPARISON_EXPR T_GREATERTHAN SHIFT_EXPR { $$ = new greaterThan($1, $3);}
          | COMPARISON_EXPR T_LESSTHANEQUAL SHIFT_EXPR { $$ = new lessEqualThan($1, $3);}
          | COMPARISON_EXPR T_GREATERTHANEQUAL SHIFT_EXPR { $$ = new greaterEqualThan($1, $3);}
          ;

EQUAL_EXPR: COMPARISON_EXPR { $$ = $1;}
          | EQUAL_EXPR T_EQUAL COMPARISON_EXPR { $$ = new equal($1,$3);}
          | EQUAL_EXPR  T_NOTEQUAL COMPARISON_EXPR { $$ = new notEqual($1,$3);}

          ;


AND_EXPR: EQUAL_EXPR { $$ = $1;}
        | AND_EXPR T_AND EQUAL_EXPR { $$ = new andOp($1,$3);}
        ;

XOR_EXPR: AND_EXPR { $$ = $1;}
                | XOR_EXPR T_XOR AND_EXPR { $$ = new xorOp($1,$3);}
                  ;

INCLUSIVE_OR_EXPR: XOR_EXPR { $$ = $1;}
                  | INCLUSIVE_OR_EXPR T_OR AND_EXPR { $$ = new orOp($1,$3);}
                  ;

LOGIC_AND_EXPR: INCLUSIVE_OR_EXPR { $$ = $1;}
                | LOGIC_AND_EXPR T_AND_OP INCLUSIVE_OR_EXPR { $$ = new LogicalAnd($1,$3);}
                ;

LOGIC_OR_EXPR: LOGIC_AND_EXPR { $$ = $1;}
                | LOGIC_OR_EXPR T_OR_OP LOGIC_AND_EXPR { $$ = new LogicalOr($1,$3);}
                ;

CONDITION_EXPR: LOGIC_OR_EXPR { $$ = $1;}
              | LOGIC_OR_EXPR T_QUESTION EXPR T_COLON CONDITION_EXPR {std::cout << "expr ? expr : condition" <<std::endl;}
              ;

ASSIGN_OP: T_ASSIGN  { $$ = $1;}
        |T_ADDEQUAL  { $$ = $1;}
        |T_DIVIDEEQUAL { $$ = $1;}
        |T_MODEQUAL {$$ = $1;}
        |T_SUBEQUAL { $$ = $1;}
        |T_MULTEQUAL { $$ = $1;}
        |T_LEFTEQUAL { $$ = $1;}
        |T_RIGHTEQUAL { $$ = $1;}
        |T_ANDEQUAL { $$ = $1;}
        |T_XOREQUAL { $$ = $1;}
        |T_OREQUAL{ $$ = $1;}
          ;

ASSIGN_EXPR: CONDITION_EXPR { $$ = $1;}
          |  UNARY_EXPR ASSIGN_OP ASSIGN_EXPR {
          if (*$2 == "="){ $$ = new assignOp($1,$3);}
          else if (*$2 == "+="){ $$ = new addAssignOp($1,$3);}
          else if (*$2 == "/="){ $$ = new divAssignOp($1,$3);}
          else if (*$2 == "%="){ $$ = new modAssignOp($1,$3);}
          else if (*$2 == "-="){ $$ = new subAssignOp($1,$3);}
          else if (*$2 == "*="){ $$ = new multAssignOp($1,$3);}
          else if (*$2 == "<<="){ $$ = new leftshiftAssignOp($1,$3);}
          else if (*$2 == ">>="){ $$ = new rightshiftAssignOp($1,$3);}
          else if (*$2 == "&="){ $$ = new andAssignOp($1,$3);}
          else if (*$2 == "^="){ $$ = new exclOrAssignOp($1,$3);}
          else if (*$2 == "|="){ $$ = new inclOrAssignOp($1,$3);}
          }
          ;

EXPR: ASSIGN_EXPR { $$ = $1;}
      | EXPR T_COMMA ASSIGN_EXPR {std::cout << "||finally an expression" <<std::endl;}
      ;

CONST_EXPR: CONDITION_EXPR { $$ = $1;}
          ;

DECLARATION:DECLARATION_SPE T_SEMICOLON{ $$ = new Variable($1);}
          | DECLARATION_SPE INITIALISE_DECLARATOR T_SEMICOLON{ $$ = new Variable($1,$2);}
          ;


DECLARATION_SPE: STORAGE_CLASS_SPE
              | STORAGE_CLASS_SPE DECLARATION_SPE
              | TYPE_SPE {  $$ = $1;}
              | TYPE_SPE DECLARATION_SPE { }
              | TYPE_QUALIFIER
              | TYPE_QUALIFIER DECLARATION_SPE
              ;

INITIALISE_DECLARATOR_LIST : INITIALISE_DECLARATOR {  $$ = new initDeclaratorList($1);}
                          | INITIALISE_DECLARATOR_LIST T_COMMA INITIALISE_DECLARATOR { $$ = new initDeclaratorList($1,$3);}
                          ;

INITIALISE_DECLARATOR: DECLARATOR { $$ = $1;}
                      | DECLARATOR T_ASSIGN VARIABLE_STORE { $$ = new assignOp($1,$3);}
                      ;

STORAGE_CLASS_SPE : T_TYPEDEF
                  | T_EXTERN
                  | T_STATIC
                  ;

TYPE_SPE: T_VOID { $$ = new voidType(*$1);}
        | T_CHAR { $$ = new charType(*$1);}
        | T_FLOAT {$$= new floatType(*$1);}
        | T_INT { $$ = new intType(*$1);}
        | T_UNSIGNED { $$ = new unsignedType(*$1);}
        | T_DOUBLE { $$ = new doubleType(*$1);}
        | ENUM_SPECIFIER
        ;

STRUCT_OR_UNION_SPE: STRUCT_OR_UNION T_VARIABLE T_LCURLY STRUCT_DECLARATION_LIST T_RCURLY {std::cout << "||struct or union spe" <<std::endl;}
                    | STRUCT_OR_UNION T_LCURLY STRUCT_DECLARATION_LIST T_RCURLY {std::cout << "||struct or union spe" <<std::endl;}
                    | STRUCT_OR_UNION T_VARIABLE {std::cout << "||struct or union w/ variable" <<std::endl;}
                    ;

STRUCT_OR_UNION: T_STRUCT {std::cout << "||struct" <<std::endl;}
                | T_UNION {std::cout << "||union" <<std::endl;}
                ;

STRUCT_DECLARATION_LIST : STRUCT_DECLARATION {$$= new structDeclarationList($1);}
                        | STRUCT_DECLARATION_LIST STRUCT_DECLARATION {$$= new structDeclarationList($1,$2);}
                        ;

STRUCT_DECLARATION: SPE_QUALIFIER_LIST STRUCT_DECLARATOR_LIST T_SEMICOLON {std::cout << "||struct declaration" <<std::endl;}
                  ;

SPE_QUALIFIER_LIST: TYPE_SPE SPE_QUALIFIER_LIST {std::cout << "||spe qualifier list" <<std::endl; $$ = new spequalifierList($1,$2);}
                  | TYPE_SPE { $$ = new spequalifierList($1); }
                  | TYPE_QUALIFIER SPE_QUALIFIER_LIST {std::cout << "||spe qualifier list3" <<std::endl;}
                  | TYPE_QUALIFIER {std::cout << "||spe qualifier list4" <<std::endl;}
                  ;

STRUCT_DECLARATOR_LIST: STRUCT_DECLARATOR { $$= new structDeclaratorList($1);}
                      | STRUCT_DECLARATOR_LIST T_COMMA STRUCT_DECLARATOR {$$= new structDeclaratorList($1,$3)}
                      ;

STRUCT_DECLARATOR: DECLARATOR {std::cout << "||struct declarator" <<std::endl;}
                | T_COLON CONST_EXPR {std::cout << "||struct declarator2" <<std::endl;}
                | DECLARATOR T_COLON CONST_EXPR {std::cout << "||struct declarator 2" <<std::endl;}
                ;

ENUM_SPECIFIER: T_ENUM T_LCURLY ENUM_LIST T_RCURLY { $$ = new enum_Spe($3);}
              | T_ENUM T_VARIABLE T_LCURLY ENUM_LIST T_RCURLY { $$ = new enum_Spe(*$2,$4);}
              | T_ENUM T_VARIABLE { $$ = new enum_Spe(*$2);}
              ;

ENUM_LIST: ENUMERATOR { $$ = new enum_List($1);}
        | ENUM_LIST T_COMMA ENUMERATOR { $$ = new enum_List($1, $3);}
        ;

ENUMERATOR: T_VARIABLE { $$ = new Enumerator(*$1);}
          | T_VARIABLE T_ASSIGN CONST_EXPR { $$ = new Enumerator(*$1,$3);}
          ;

TYPE_QUALIFIER: T_CONST
              | T_VOLATILE
              ;


DECLARATOR: DIRECT_DECL {  $$ = $1;}
          ;

DIRECT_DECL: T_VARIABLE { $$ = new VariableName(*$1); }
          | T_LBRACKET DECLARATOR T_RBRACKET { $$ = $2;}
          | DIRECT_DECL L_SQRBRACKET CONST_EXPR R_SQRBRACKET{ $$ = new array_declaration($1,$3);}
          | DIRECT_DECL L_SQRBRACKET R_SQRBRACKET { $$ = new array_declaration($1);}
          | DIRECT_DECL T_LBRACKET PARAM_TYPE_LIST T_RBRACKET { $$ = new function_decl($1,$3);}
          | DIRECT_DECL T_LBRACKET T_VARIABLE_LIST T_RBRACKET { $$ = new function_decl($1,$3);}
          | DIRECT_DECL T_LBRACKET T_RBRACKET { $$ = new function_decl($1);}
          ;

POINTER: T_MULTIPLY {std::cout <<"||pointer" << std::endl;}
      | T_MULTIPLY TYPE_QUALIFIER_LIST{std::cout <<"||pointer2" << std::endl;}
      | T_MULTIPLY POINTER {std::cout <<"||pointer3" << std::endl;}
      | T_MULTIPLY TYPE_QUALIFIER_LIST POINTER {std::cout <<"||pointer4" << std::endl;}
      ;


TYPE_QUALIFIER_LIST: TYPE_QUALIFIER {$$= new typeQualifierList($1);}
                  | TYPE_QUALIFIER_LIST TYPE_QUALIFIER {$$= new typeQualifierList($1,$2);}
                  ;

PARAM_TYPE_LIST: PARAM_LIST { $$=$1;}
                | PARAM_LIST T_COMMA T_ELLIPSIS { $$=$1;}
                ;

PARAM_LIST : PARAM_DECLARATION { $$ = new param_list($1);}
          | PARAM_LIST T_COMMA PARAM_DECLARATION { $$ = new param_list($1,$3);}
          ;

PARAM_DECLARATION : DECLARATION_SPE DECLARATOR { $$ = new Variable($1,$2);}
                | DECLARATION_SPE { $$ = new Variable($1);}
          	     ;

T_VARIABLE_LIST: T_VARIABLE { $$ = new VariableName(*$1);}
               | T_VARIABLE_LIST T_COMMA T_VARIABLE { $$ = new variableList($1,new VariableName(*$3));}
               ;

TYPE_NAME: SPE_QUALIFIER_LIST { $$ = $1;}
          | SPE_QUALIFIER_LIST ABS_DECLARATOR {std::cout <<"||type name2" << std::endl;}
          ;

ABS_DECLARATOR: POINTER {std::cout <<"||abs declarator" << std::endl;}
              | DIRECT_ABS_DECLARATOR {std::cout <<"||abs declarator 2" << std::endl;}
              | POINTER DIRECT_ABS_DECLARATOR {std::cout <<"||abs declarator 3" << std::endl;}
              ;

DIRECT_ABS_DECLARATOR: T_RBRACKET ABS_DECLARATOR T_LBRACKET {std::cout <<"||direct abs declarator" << std::endl;}
                      | L_SQRBRACKET R_SQRBRACKET {std::cout <<"||direct abs declarator2" << std::endl;}
                      | L_SQRBRACKET CONST_EXPR R_SQRBRACKET {std::cout <<"||direct abs declarator3" << std::endl;}
                      | DIRECT_ABS_DECLARATOR L_SQRBRACKET R_SQRBRACKET {std::cout <<"||direct abs declarator4" << std::endl;}
                      | DIRECT_ABS_DECLARATOR L_SQRBRACKET CONST_EXPR R_SQRBRACKET {std::cout <<"||direct abs declarator5" << std::endl;}
                      | T_LBRACKET T_RBRACKET {std::cout <<"||direct abs declarator6" << std::endl;}
                      | T_LBRACKET PARAM_TYPE_LIST T_RBRACKET {std::cout <<"||direct abs declarator7" << std::endl;}
                      | DIRECT_ABS_DECLARATOR T_LBRACKET T_RBRACKET {std::cout <<"||direct abs declarator 8" << std::endl;}
                      | DIRECT_ABS_DECLARATOR T_LBRACKET PARAM_TYPE_LIST T_LBRACKET {std::cout <<"||direct abs declarator 9" << std::endl;}
                      ;

VARIABLE_STORE: ASSIGN_EXPR { $$ = $1;}
        | T_LCURLY VARIABLE_STORE_LIST T_RCURLY { $$ = $2;}
        | T_LCURLY VARIABLE_STORE_LIST T_COMMA T_RCURLY { $$ = $2;}
        ;


VARIABLE_STORE_LIST: VARIABLE_STORE { $$ = new variableStoreList($1);}
        | VARIABLE_STORE_LIST T_COMMA VARIABLE_STORE { new variableStoreList($1,$3);}
        ;

STATEMENT: LABELED_STATEMENT { $$ = $1;}
          | COMPOUND_STATEMENT { $$ = $1;}
          | EXPR_STATEMENT { $$ = $1;}
          | SELECT_STATEMENT { $$ = $1;}
          | ITERATION_STATEMENT { $$ = $1;}
          | JUMP_STATEMENT { $$ = $1;}
          ;

LABELED_STATEMENT: T_VARIABLE T_COLON STATEMENT {std::cout << "||LABALLED STATEMENT" <<std::endl;}
                  | T_CASE CONST_EXPR T_COLON STATEMENT { $$= new switchstmntcase($2,$4);}
                  | T_DEFAULT T_COLON STATEMENT { $$= new switchdefault($3);}
                  ;

COMPOUND_STATEMENT: T_LCURLY T_RCURLY { $$ = new compound_stmnt();}
                  | T_LCURLY STATEMENT_LIST T_RCURLY { $$ = new compound_stmnt($2);}
                  | T_LCURLY DECLARATION_LIST T_RCURLY { $$ = new compound_stmnt($2);}
                  | T_LCURLY DECLARATION_LIST STATEMENT_LIST T_RCURLY { $$ = new compound_stmnt($2, $3);}
                  ;

DECLARATION_LIST: DECLARATION { $$= new declarationlist($1);}
                | DECLARATION_LIST DECLARATION { $$= new declarationlist($1,$2);}
                ;

STATEMENT_LIST : STATEMENT {$$= new stmntlist($1);}
              | STATEMENT_LIST STATEMENT {$$= new stmntlist($1,$2);}
              ;

EXPR_STATEMENT: T_SEMICOLON {std::cout << "||expr statement" <<std::endl;}
              | EXPR T_SEMICOLON { $$ = $1;}
              ;


SELECT_STATEMENT: T_IF T_LBRACKET EXPR T_RBRACKET STATEMENT { $$ = new ifstate($3,$5);}
                | T_IF T_LBRACKET EXPR T_RBRACKET STATEMENT T_ELSE STATEMENT { $$ = new if_Elsestate($3,$5,$7);}
                | T_SWITCH T_LBRACKET EXPR T_RBRACKET STATEMENT { $$ = new switchstmnt($3,$5);}
                ;

ITERATION_STATEMENT: T_WHILE T_LBRACKET EXPR T_RBRACKET STATEMENT { $$ = new whilestmnt($3,$5);}
                | T_DO STATEMENT T_WHILE T_RBRACKET EXPR T_LBRACKET T_SEMICOLON
                | T_FOR T_LBRACKET EXPR_STATEMENT EXPR_STATEMENT T_RBRACKET STATEMENT { $$ = new forloop($3, $4, $6);}
                | T_FOR T_LBRACKET EXPR_STATEMENT EXPR_STATEMENT EXPR T_RBRACKET STATEMENT { $$ = new forloop($3, $4, $5, $7);}
                | T_FOR T_LBRACKET DECLARATION EXPR_STATEMENT EXPR T_RBRACKET STATEMENT { $$ = new forloop($3, $4, $5, $7);}
                ;

JUMP_STATEMENT: GOTO T_VARIABLE T_SEMICOLON
              | T_CONTINUE T_SEMICOLON { $$ = new Continue();}
              | T_BREAK T_SEMICOLON {$$ = new Break();}
              | T_RETURN T_SEMICOLON {}
              | T_RETURN EXPR T_SEMICOLON { $$= new return_stmnt($2);}
              ;

TRANSLATION_UNIT: EXTERN_DECL { $$ = new listthg($1);}
                | TRANSLATION_UNIT EXTERN_DECL { $$ = new listthg($1,$2);}
                ;

EXTERN_DECL : FUNCT_DEF { $$ = $1;}
            | DECLARATION { $$ = $1;}
            ;

FUNCT_DEF: DECLARATION_SPE DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT {  $$ = new function_def($1, $2,$3, $4);}
        | DECLARATION_SPE DECLARATOR COMPOUND_STATEMENT { $$ = new function_def($1, $2,$3);}
        | DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT { $$ = new function_def($1, $2,$3);}
        | DECLARATOR COMPOUND_STATEMENT {$$ = new function_def($1, $2);}
        ;




ROOT:   TRANSLATION_UNIT  { g_root = new top($1);}
;
%%

Node *g_root; // Definition of variable (to match declaration earlier)

Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
