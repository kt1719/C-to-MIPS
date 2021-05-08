#ifndef ast_list_hpp
#define ast_list_hpp

#include "ast_node.hpp"

class listthg
    : public Node
{

public:
    listthg() {}
    listthg(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    listthg(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "LIST";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate() override {
        float x = branches.size();
        for (int i = 0; i < branches.size(); i++) {
            if (branches[i] == NULL) {
                x--;
            }
        }
        return x;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};

class stmntlist
    : public Node
{

public:
    stmntlist(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    stmntlist(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "StatementList";
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
/*
if (branches[1] != NULL) {
    if (branches[0]->returntype() == "VariableName") {
        return 1;
    }
}
else if (branches[1]->returntype() == "VariableName") {
    int x = branches[0]->evaluate();
    return x + 1;
}*/

class declarationlist
    : public Node
{
public:
    declarationlist(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    declarationlist(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "DeclarationList";
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

class initDeclaratorList
    : public Node
{

public:
    initDeclaratorList(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    initDeclaratorList(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "InitDeclaratorList";
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

class typeQualifierList
    : public Node
{

public:
    typeQualifierList(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    typeQualifierList(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "TYPE QUALIFIER LIST";
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

class structDeclarationList
    : public Node
{

public:
    structDeclarationList(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    structDeclarationList(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "STRUCT declaratION LIST";
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

class variableStoreList
    : public Node
{
public:
    variableStoreList(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    variableStoreList(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }
    virtual void replacearg(NodePtr x) override {}
    std::string type = "VARIABLE STORE LIST";
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
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};

class structDeclaratorList
    : public Node
{
public:
    structDeclaratorList(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    structDeclaratorList(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "STRUCT declarator LIST";
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

class variableList
    : public Node
{
public:

    variableList(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "Variable LIST";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate() {
        return 0;
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};
class spequalifierList
    : public Node
{
public:

    spequalifierList(NodePtr exp)
    {
        branches.push_back(exp);
        branches.push_back(NULL);
    }

    spequalifierList(NodePtr exp, NodePtr exp2)
    {
        branches.push_back(exp);
        branches.push_back(exp2);
    }

    std::string type = "Spe Qualifier LIST";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate() {
        return 0;
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override { return ""; }
};
#endif
