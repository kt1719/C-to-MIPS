#ifndef ast_array_hpp
#define ast_array_hpp

#include "ast_node.hpp"

class array_declaration // if (expr) {statement}
    : public Node
{

public:
    array_declaration(NodePtr exp)
    {
      branches.push_back(exp);
      branches.push_back(NULL);
    }
    array_declaration(NodePtr exp, NodePtr exp2)
    {
      branches.push_back(exp);
      branches.push_back(exp2);
    }

    ~array_declaration(){}
    std::string type = "Array Declaration";
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

class array_identifier // if (expr) {statement}
    : public Node
{

public:
    array_identifier(NodePtr exp, NodePtr exp2)
    {
      branches.push_back(exp);
      branches.push_back(exp2);
    }

    ~array_identifier(){}
    std::string type = "Array Identifier";
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
