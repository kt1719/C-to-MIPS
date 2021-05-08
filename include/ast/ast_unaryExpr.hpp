#ifndef ast_unaryExpr_hpp
#define ast_unaryExpr_hpp

#include "ast_node.hpp"

class unaryExpr
    : public Node
{
private:
    std::string unary;
public:
    unaryExpr(const std::string &_id, NodePtr node)
        : unary(_id)
    {
        branches.push_back(node);
    }

    unaryExpr(NodePtr node, const std::string&_id)
        : unary(_id)
    {
        branches.push_back(node);
    }

    std::string type = "UnaryExpr";
    virtual std::string returntype() override {
        return type;
    } //return VariableName useful for codegen

    virtual NodePtr getbranch(int x) override {
        return branches[0];
    } //
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate() override {
        return branches[0]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return unary;
    }
};

#endif
