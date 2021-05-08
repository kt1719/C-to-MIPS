#ifndef ast_function_hpp
#define ast_function_hpp
#include <algorithm>
#include "ast_node.hpp"

class function_def // if (expr) {statement}
    : public Node
{
/*protected:
    NodePtr decl_spe;
    NodePtr decl;
    NodePtr decl_list;
    NodePtr cmp_stmnt;*/
public:
    function_def(NodePtr exp, NodePtr exp1,NodePtr exp2, NodePtr exp3)
    {
      branches.push_back(exp);
      branches.push_back(exp1);
      branches.push_back(exp2);
      branches.push_back(exp3);
    }

    function_def(NodePtr exp, NodePtr exp1,NodePtr exp3)
    {
        if (exp->returntype() == "inttype") {
            branches.push_back(exp);
            branches.push_back(exp1);
            branches.push_back(NULL);
            branches.push_back(exp3);
        }
        else if (exp->returntype() == "CharType") {
            branches.push_back(exp);
            branches.push_back(exp1);
            branches.push_back(NULL);
            branches.push_back(exp3);
        }
        else if (exp->returntype() == "UnsignedType") {
            branches.push_back(exp);
            branches.push_back(exp1);
            branches.push_back(NULL);
            branches.push_back(exp3);
        }
        else if (exp->returntype() == "FloatType") {
            branches.push_back(exp);
            branches.push_back(exp1);
            branches.push_back(NULL);
            branches.push_back(exp3);
        }
        else if (exp->returntype() == "DoubleType") {
            branches.push_back(exp);
            branches.push_back(exp1);
            branches.push_back(NULL);
            branches.push_back(exp3);
        }
        else {
            branches.push_back(NULL);
            branches.push_back(exp);
            branches.push_back(exp1);
            branches.push_back(exp3);
        }
    }

    function_def( NodePtr exp1, NodePtr exp3)
    {
      branches.push_back(NULL);
      branches.push_back(exp1);
      branches.push_back(NULL);
      branches.push_back(exp3);
    }

    std::string type = "Function";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
            return branches[1]->evaluate();
    }

    virtual std::string name() override {
        return "";
    }

    virtual std::vector<std::string>  returnname() override {
        if (branches[3] != NULL) {
            return branches[3]->returnname();
        }
        else {
            return std::vector<std::string>();
            
        }
    }
    virtual void replacearg(NodePtr x) override {}
};
class function_decl // int x(param up to 4)
    : public Node
{
public:
    function_decl(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    function_decl(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "Function Declaration";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() {
        if (branches[1] != NULL) {
            //std::cout << branches[1]->returntype() << std::endl;
            if (branches[1]->returntype() != "Variable") {

                return branches[1]->evaluate();
            }
            else {
                return 1;
            }
        }
        else {
            return 0;
        }
    }

    virtual std::string name() override {
        return branches[0]->name();
    }

    virtual std::vector<std::string>  returnname() override {
        return branches[0]->returnname();
        return branches[1]->returnname();
    }

    virtual void replacearg(NodePtr x) override {
        branches.push_back(x);
    }
};

#endif
