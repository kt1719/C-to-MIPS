%option noyywrap

%{

#include "parser.tab.hpp"

%}
SMALL [a-z_]
CHARS [A-Za-z0-9_]
D [0-9]
E	[Ee][+-]?{D}+
FS (f|F|l|L)
%%

"break"   {  return T_BREAK;}
"case"    {  return T_CASE;}
"const"   {  return T_CONST;}
"continue" {  return T_CONTINUE;}
"default" {  return T_DEFAULT;}
"do"      {  return T_DO;}
"else"    {  return T_ELSE;}
"enum"    {  return T_ENUM;}
"extern"  {  return T_EXTERN;}
"for"     { return T_FOR; }
"goto"    {  return GOTO;}
"if"      { return T_IF;}
"return"  {  return T_RETURN;}
"sizeof"  { return T_SIZEOF;}
"static"  {  return T_STATIC;}
"struct"  { return T_STRUCT;}
"switch"  {  return T_SWITCH;}
"typedef" {  return T_TYPEDEF;}
"union"   { return T_UNION;}
"volatile" {  return T_VOLATILE;}
"while"	  { return T_WHILE; }
"int"	    { std::string s(yytext); yylval.string = new std::string(s); return T_INT;}
"char"    { std::string s(yytext); yylval.string = new std::string(s);return T_CHAR;}
"float"   { std::string s(yytext); yylval.string = new std::string(s); return T_FLOAT;}
"unsigned" {std::string s(yytext); yylval.string = new std::string(s);return T_UNSIGNED;}
"double" { std::string s(yytext); yylval.string = new std::string(s);return T_DOUBLE;}
"void"    { std::string s(yytext); yylval.string = new std::string(s); return T_VOID;}

{D}+			     {  yylval.number = atof(yytext); return T_NUM; }
\'[a-zA-Z0-9]\'		{  std::string s(yytext); yylval.string = new std::string(s); return T_CHARVAL; }
{SMALL}+{CHARS}* {  std::string s(yytext); yylval.string = new std::string(s); return T_VARIABLE; }
{D}+{E}{FS}?         		{ return T_NUM; }
{D}*"."{D}+({E})?{FS}?	{ return T_NUM; }
{D}+"."{D}*({E})?{FS}?	{ return T_NUM; }


"("             {  return T_LBRACKET;}
")"             {  return T_RBRACKET;}
[\[]            { return L_SQRBRACKET;}
[\]]            {  return R_SQRBRACKET;}
"{"             {  return T_LCURLY;}
"}"             {  return T_RCURLY;}
"=="            {  return T_EQUAL;}
"!="            { return T_NOTEQUAL;}
"+="            {  std::string s(yytext); yylval.string = new std::string(s); fprintf(stderr, "Not Equal \n"); return T_ADDEQUAL;}
"/="            {  std::string s(yytext); yylval.string = new std::string(s); return T_DIVIDEEQUAL;}
"%="            {  std::string s(yytext); yylval.string = new std::string(s); return T_MODEQUAL;}
"-="            {  std::string s(yytext); yylval.string = new std::string(s); return T_SUBEQUAL;}
"*="            { std::string s(yytext); yylval.string = new std::string(s); return T_MULTEQUAL;}
"<<="           {  std::string s(yytext); yylval.string = new std::string(s); return T_LEFTEQUAL;}
">>="           {  std::string s(yytext); yylval.string = new std::string(s); return T_RIGHTEQUAL;}
"&="            { std::string s(yytext); yylval.string = new std::string(s); return T_ANDEQUAL;}
"^="            { std::string s(yytext); yylval.string = new std::string(s); return T_XOREQUAL;}
"|="            {  std::string s(yytext); yylval.string = new std::string(s); return T_OREQUAL;}
"=" 		   	{  std::string s(yytext); yylval.string = new std::string(s); return T_ASSIGN;}
"*"             {  std::string s(yytext); yylval.string = new std::string(s); return T_MULTIPLY;}
"++"            {  std::string s(yytext); yylval.string = new std::string(s); return INC_OP;}
"--"            {  std::string s(yytext); yylval.string = new std::string(s); return DEC_OP;}
"+"             {   std::string s(yytext); yylval.string = new std::string(s);return T_ADD; }
"^"             {  std::string s(yytext); yylval.string = new std::string(s); return T_XOR; }
"-"             {  std::string s(yytext); yylval.string = new std::string(s); return T_SUB; }
"~"             { std::string s(yytext); yylval.string = new std::string(s);return T_INVERT;}
"%"             {  return T_MODULO;}
"/"	      	    {  return T_DIV; }
"&"           	{  return T_AND; }
"&&"            {  return T_AND_OP; }
"!"	    	    {  std::string s(yytext); yylval.string = new std::string(s);return T_NOT; }
"?"	    	    {  return T_QUESTION; }
","		        {return T_COMMA;}
"..."           { return T_ELLIPSIS;}
"."             { return T_PERIOD;}
"|"             {  return T_OR;}
"||"		    {  return T_OR_OP;}
"<<"            {  return T_SHIFTLEFT;}
">>"            {  return T_SHIFTRIGHT;}
"<="            {  return T_LESSTHANEQUAL;}
">="            {  return T_GREATERTHANEQUAL;}
"<"             {  return T_LESSTHAN;}
">"             {  return T_GREATERTHAN;}
":"             {  return T_COLON;}
";"             { return T_SEMICOLON;}
[ \t\r\n]+	   	{;}
.               { ; }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
