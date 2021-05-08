#ifndef ast_compound_stmnt_hpp
#define ast_compound_stmnt_hpp

#include "ast_node.hpp"

class compound_stmnt // if (expr) {statement}
    : public Node
{

public:
    compound_stmnt(){
      branches.push_back(NULL);
      branches.push_back(NULL);
    }

    compound_stmnt(NodePtr exp)
    {
      branches.push_back(exp);
      branches.push_back(NULL);
    }

    compound_stmnt(NodePtr exp, NodePtr exp1)
    {
        branches.push_back(exp);
        branches.push_back(exp1);
    }
    virtual void replacearg(NodePtr x) override {}
    std::string type = "Compound Statement";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() {
        return 0;
    }

    virtual std::vector<std::string>  returnname() override {
        if (branches[0] == NULL) {
            return std::vector<std::string>();
        }
        else if (branches[0]->returntype() == "MultList") {
            return branches[0]->returnname();
        }
        else if(branches[0]->returntype() == "Variable"){
            std::vector<std::string> returningvec;
            returningvec.push_back(branches[0]->name());
            return returningvec;
        }
        else {
            return std::vector<std::string>();
        }
    }

    virtual std::string name() override {
        return "";
    }
};
#endif
