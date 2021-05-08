#ifndef ast_basics_hpp
#define ast_basics_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"

class VariableName
    : public Node
{
private:
    std::string name1;
public:
    VariableName(const std::string &_id)
        : name1(_id)
    {} //assigns what u put in parenthesis to what is in red: so here the string is stored in name

    std::string type = "VariableName";
    virtual std::string returntype() override {
        return type;
    } //return VariableName useful for codegen

    virtual NodePtr getbranch(int x) override {
        return NULL;
    } //

    virtual float evaluate() override {
      return 0;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return name1;
    }
};

class CharName
    : public Node
{
private:
    char name1;
public:
    CharName(std::string& _id)
        : name1(_id[1])
    {} //assigns what u put in parenthesis to what is in red: so here the string is stored in name

    std::string type = "CharName";
    virtual std::string returntype() override {
        return type;
    } //return VariableName useful for codegen

    virtual NodePtr getbranch(int x) override {
        return NULL;
    } //

    virtual float evaluate() override {
        return name1;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};


class Number
    : public Node
{
private:
    double value;
public:
    Number(double _value)
        : value(_value)
    {}

    std::string type = "Number";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override{
        return NULL;
      }
    virtual void replacearg(NodePtr x) override {}
    virtual float evaluate() override {
        return value;
      }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

#endif
