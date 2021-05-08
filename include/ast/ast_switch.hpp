#ifndef ast_switch_hpp
#define ast_switch_hpp

#include "ast_node.hpp"

class switchstmnt // if (expr) {statement}
    : public Node
{

public:
    switchstmnt(NodePtr conditionexp, NodePtr stmnt)
    { }

    std::string type = "Switch";
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

class switchstmntcase //
    : public Node
{

public:
    switchstmntcase(NodePtr numofstmnt, NodePtr exp)
    { }

    std::string type = "Switch w/ Case";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() {
        return 0;
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};

class switchdefault // default : statement
    : public Node
{

public:
    switchdefault(NodePtr exp)
    { }

    std::string type = "Switch Default";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() {
        return 0;
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};

#endif
