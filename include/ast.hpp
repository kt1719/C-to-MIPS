#ifndef ast_hpp
#define ast_hpp

#include <string>
#include "ast/ast_basics.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_variable.hpp"
#include "ast/ast_bitwiseOp.hpp"
#include "ast/ast_assignOp.hpp"
#include "ast/ast_arithmeticOp.hpp"
#include "ast/ast_logicalOp.hpp"
#include "ast/ast_comparisonOp.hpp"
#include "ast/ast_int.hpp"
#include "ast/ast_top.hpp"
#include "ast/ast_function.hpp"
#include "ast/ast_conditional.hpp"
#include "ast/ast_compound_stmnt.hpp"
#include "ast/ast_while_for.hpp"
#include "ast/ast_enum.hpp"
#include "ast/ast_return_break_cont.hpp"
#include "ast/ast_switch.hpp"
#include "ast/ast_unaryOp.hpp"
#include "ast/ast_unaryExpr.hpp"
#include "ast/ast_param.hpp"
#include "ast/ast_list.hpp"
#include "ast/ast_array.hpp"
#include "ast/ast_char.hpp"

extern Node* parseAST();


#endif
