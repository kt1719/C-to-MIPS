#ifndef ast_unaryOp_hpp
#define ast_unaryOp_hpp

#include "ast_node.hpp"

class unaryOp
    : public Node
{
private:
    std::string unary;
public:
    unaryOp(const std::string &_id, NodePtr node)
        : unary(_id)
    {
        branches.push_back(node);
    }

    std::string type = "UnaryOp";
    virtual std::string returntype() override {
        return type;
    } //return VariableName useful for codegen

    virtual NodePtr getbranch(int x) override {
        return branches[0];
    } //

    virtual float evaluate() override {
        return branches[0]->evaluate();
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return unary;
    }
};

#endif
