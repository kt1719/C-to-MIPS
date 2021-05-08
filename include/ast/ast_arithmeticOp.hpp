#ifndef ast_arithmeticOp_hpp
#define ast_arithmeticOp_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

#include "ast_node.hpp"

class addOp
    : public Node
{
public:
    addOp(NodePtr left, NodePtr right)

    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "AddOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return branches[0]->evaluate()+branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
    virtual void replacearg(NodePtr x) override {}
};

class subOp
    : public Node
{

public:
    subOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left)
        ;
        branches.push_back(right);
    }

    std::string type = "SubOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return branches[0]->evaluate()-branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
    virtual void replacearg(NodePtr x) override {}
};

class multOp
    : public Node
{
public:
    multOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "MultOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return branches[0]->evaluate()*branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
    virtual void replacearg(NodePtr x) override {}
};

class divOp
    : public Node
{
public:
    divOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "DivOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return branches[0]->evaluate()/branches[1]->evaluate();
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
    virtual void replacearg(NodePtr x) override {}
};

class modOp
    : public Node
{

public:
    modOp(NodePtr left, NodePtr right)
    {
        branches.push_back(left);
        branches.push_back(right);
    }

    std::string type = "ModOp";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return (unsigned int)branches[0]->evaluate()% (unsigned int)branches[1]->evaluate();
    }
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
    virtual void replacearg(NodePtr x) override {}
};

//Missing Increment and decrement

#endif
