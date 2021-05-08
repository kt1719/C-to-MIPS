#ifndef ast_comparisonOp_hpp
#define ast_comparisonOp_hpp


#include "ast_node.hpp"

class equal // a==b
    : public Node
{

public:
    equal(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "Equal";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 1;
    }
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::string name() override {
        return "";
    }
};

class notEqual // a!=b
    : public Node
{
public:
    notEqual(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "NotEqual";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 1;
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class greaterThan // a>b
    : public Node
{
public:
    greaterThan(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "GreaterThan";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate(){
      return 1;
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class lessThan // a<b
    : public Node
{
public:
    lessThan(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "LessThan";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 1;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class greaterEqualThan //a>=b
    : public Node
{

public:
    greaterEqualThan(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "GreaterEqualThan";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 1;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class lessEqualThan //a<=b
    : public Node
{
public:
    lessEqualThan(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "LessEqualThan";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 1;
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
