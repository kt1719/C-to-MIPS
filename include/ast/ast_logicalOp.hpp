#ifndef ast_logicalOp_hpp
#define ast_logicalOp_hpp

#include "ast_node.hpp"

class LogicalAnd // a&&b
    : public Node
{
public:
    LogicalAnd(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "LogicalAnd";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return branches[0]->evaluate()&&branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::string name() override {
        return "";
    }
};

class LogicalOr // a||b
    : public Node
{
public:
    LogicalOr(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "LogicalOr";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate(){
      return branches[0]->evaluate()||branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

#endif