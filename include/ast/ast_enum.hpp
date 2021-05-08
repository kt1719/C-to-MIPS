#ifndef ast_enum_hpp
#define ast_enum_hpp

#include "ast_node.hpp"

class Enumerator // enum ___ {a,b,c,...}
    : public Node
{
private:
  std::string enumname;
public:
    Enumerator(std::string& _id) :
        enumname(_id)
    {
        branches.push_back(NULL);
    }
    Enumerator(std::string &_id, NodePtr left):
    enumname(_id)
    {
        branches.push_back(left);
    }

    std::string type = "Enumerator";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
        return branches[1]->evaluate();
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override { return std::vector<std::string>();}

    virtual std::string name() override { return enumname; }
};

class enum_Spe // enum ___ {a,b,c,...}
    : public Node
{
private:
  std::string enumname;
public:

    enum_Spe(std::string &_id, NodePtr left)
    : enumname(_id)
    {
        branches.push_back(left);
    }

    enum_Spe(std::string &_id)
    : enumname(_id)
    {
        branches.push_back(NULL);
    }

    enum_Spe(NodePtr left)
    {
      branches.push_back(left);}

    std::string type = "Enum Specifier";
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

    virtual std::vector<std::string>  returnname() override { return std::vector<std::string>();}

    virtual std::string name() override { return enumname; }
};

class enum_List // enum ___ {a,b,c,...}
    : public Node
{
public:
    enum_List(NodePtr left)
    {
      branches.push_back(left);
      branches.push_back(NULL);
    }

    enum_List(NodePtr left, NodePtr right)
    {
      branches.push_back(left);
      branches.push_back(right);
    }
    std::string type = "Enum List";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
        if (branches[1] == NULL) {
            return 1;
        }
        else {
            int x = branches[0]->evaluate();
            return 1 + x;
        }
    }

    virtual std::vector<std::string>  returnname() override { return std::vector<std::string>();}

    virtual std::string name() override { return ""; }
};
#endif
