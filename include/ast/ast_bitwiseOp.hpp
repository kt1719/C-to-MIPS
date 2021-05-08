#ifndef ast_bitwiseOp_hpp
#define ast_bitwiseOp_hpp


#include "ast_node.hpp"

class andOp //a&b
    : public Node
{
public:
    andOp(NodePtr left, NodePtr right)

    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "AndOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return (unsigned int)branches[0]->evaluate() & (unsigned int)branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::string name() override {
        return "";
    }
};

class orOp //a|b
    : public Node
{
public:
    orOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "OrOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate(){
      return (unsigned int)branches[0]->evaluate() | (unsigned int)branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class xorOp //a^b
    : public Node
{
public:
    xorOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "XorOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate(){
      return (unsigned int)branches[0]->evaluate()^ (unsigned int)branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class leftShiftOp //a<<b
    : public Node
{
public:
    leftShiftOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "LeftShiftOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return (unsigned int)branches[0]->evaluate()<< (unsigned int)branches[1]->evaluate();
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class rightShiftOp //a>>b
    : public Node
{
public:
    rightShiftOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "RightShiftOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return (unsigned int)branches[0]->evaluate()>> (unsigned int)branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::string name() override {
        return "";
    }
};
#endif
