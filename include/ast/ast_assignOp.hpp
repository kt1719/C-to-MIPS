#ifndef ast_assignOp_hpp
#define ast_assignOp_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

#include "ast_node.hpp"

class assignOp //a=b
    : public Node
{
public:
    assignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "AssignOp";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return branches[1]->evaluate();
      //doesnt matter
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return branches[0]->name();
    }
};

class addAssignOp //a+=b
    : public Node
{
public:
    addAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "AddAssignOp";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override {
        return branches[0]->name();
    }
};

class subAssignOp //a-=b
    : public Node
{
public:
    subAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }
    virtual void replacearg(NodePtr x) override {}
    std::string type = "subAssignOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return branches[0]->name();
    }
};

class multAssignOp //a*=b
    : public Node
{
public:
    multAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }
    virtual void replacearg(NodePtr x) override {}
    std::string type = "multAssignOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return branches[0]->name();
    }
};

class divAssignOp //a/=b
    : public Node
{
public:
    divAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }
    virtual void replacearg(NodePtr x) override {}
    std::string type = "divAssignOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return branches[0]->name();
    }
};

class modAssignOp //a/=b
    : public Node
{
public:
    modAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "ModAssignOp";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return branches[0]->name();
    }
};

class leftshiftAssignOp //a<<=b
    : public Node
{
public:
    leftshiftAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "LeftShiftAssignOp";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override {
        return branches[0]->name();
    }
};

class rightshiftAssignOp //a>>=b
    : public Node
{
public:
    rightshiftAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }
    virtual void replacearg(NodePtr x) override {}
    std::string type = "RightShiftAssignOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
    virtual std::string name() override {
        return branches[0]->name();
    }
};

class andAssignOp //a&=b
    : public Node
{
public:
    andAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "AndAssignOp";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return branches[0]->name();
    }
};

class exclOrAssignOp //a^=b
    : public Node
{
public:
    exclOrAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "ExclOrAssignOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate(){
      return 0;
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return branches[0]->name();
    }
};

class inclOrAssignOp //a|=b
    : public Node
{
public:
    inclOrAssignOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "InclOrAssignOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;//doesnt matter
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return branches[0]->name();
    }
};
#endif
