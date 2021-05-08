#ifndef ast_while_for_hpp
#define ast_while_for_hpp

#include "ast_node.hpp"

class whilestmnt
    : public Node
{

public:
    whilestmnt(NodePtr left, NodePtr right)
    {
      branches.push_back(left);
      branches.push_back(right);
    }

    std::string type = "While";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;
    }

    virtual std::string name() override {
        return "";
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
            return branches[1]->returnname();
    }
};

class forloop
    : public Node
{

public:
    forloop(NodePtr part1, NodePtr part2, NodePtr thing)
    {
      branches.push_back(part1);
      branches.push_back(part2);
      branches.push_back(NULL);
      branches.push_back(thing);
    }

    forloop(NodePtr part1, NodePtr part2, NodePtr morepart, NodePtr thing)
    {
      branches.push_back(part1);
      branches.push_back(part2);
      branches.push_back(morepart);
      branches.push_back(thing);
    }

    std::string type = "For Loop";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }

    virtual float evaluate(){
      return 0;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::string name() override {
        return "";
    }

    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }
};

#endif
