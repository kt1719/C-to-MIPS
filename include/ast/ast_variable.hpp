#ifndef ast_variable_hpp
#define ast_variable_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

#include "ast_node.hpp"

class Variable
    : public Node
{
public:
    ~Variable(){}
    Variable(NodePtr type, NodePtr expr)
    {
        branches.push_back(type);
        branches.push_back(expr);
    }
    Variable(NodePtr type)
    {
        branches.push_back(NULL);
        branches.push_back(type);
        
    }


    std::string type = "Variable";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() override {
        if (branches[1]->returntype() == "Number") {
            return branches[1]->evaluate();
        }

    }
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        if (branches[0] != NULL) {
            return branches[1]->name();
        }
        else {
            return std::to_string((int)branches[1]->evaluate());
        }
    }
};
#endif
