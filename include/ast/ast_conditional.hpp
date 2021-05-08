#ifndef ast_conditional_hpp
#define ast_conditional_hpp

#include "ast_node.hpp"

class ifstate // if (expr) {statement}
    : public Node
{
public:
    ifstate(NodePtr condition, NodePtr statement)
    {
      branches.push_back(condition);
      branches.push_back(statement);
    }

    NodePtr ifcondition(){
      return branches[0];
    }

    NodePtr ifstatement(){
      return branches[1];
    }

    std::string type = "IFStatement";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return branches[0]->evaluate();
    }

    virtual std::string name() override {
        return "";
    }

    virtual std::vector<std::string>  returnname() override {
        return branches[1]->returnname();
    }
};

class if_Elsestate // if(expr){statement}else{statement}
    : public Node
{
public:
    if_Elsestate(NodePtr condition, NodePtr statement, NodePtr elsestmnt)
    {
      branches.push_back(condition);
      branches.push_back(statement);
      branches.push_back(elsestmnt);
    }

    NodePtr ifelsecondition(){
      return branches[0];
    }

    NodePtr ifstatement(){
      return branches[1];
    }

    NodePtr elsestatement(){
    return branches[2];
  }

    std::string type = "IFElseStatement";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return branches[0]->evaluate();
    }

    virtual std::string name() override {
        return "";
    }

    virtual std::vector<std::string>  returnname() override {
        return branches[1]->returnname();
    }
};

#endif
