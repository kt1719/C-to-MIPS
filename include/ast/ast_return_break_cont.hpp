#ifndef ast_return_break_cont_hpp
#define ast_return_break_cont_hpp

#include "ast_node.hpp"

class return_stmnt // if (expr) {statement}
    : public Node
{

public:
    return_stmnt(NodePtr exp)
    {
      branches.push_back(exp);
    }

    std::string type = "Return";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() {
        return 0;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};

class Break
    : public Node
{

public:
    Break(){}

    std::string type = "Break";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() {
        return 0;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};

class Continue
    : public Node
{

public:
    Continue(){}

    std::string type = "Continue";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() {
        return 0;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};
#endif
