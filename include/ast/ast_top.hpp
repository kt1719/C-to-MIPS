#ifndef ast_top_hpp
#define ast_top_hpp


#include "ast_node.hpp"

class top 
    : public Node
{

public:
    top(NodePtr program)
    {
        branches.push_back(program);
    }

    std::string type = "Program";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
    if (x == 0){
        return branches[x];
        }
        else{
        return NULL;
        }
    }
    virtual void replacearg(NodePtr x) override {}
    
    virtual float evaluate() override{
      return branches.size();
    }

    virtual std::string name() override {
        return "";
    }

    virtual std::vector<std::string>  returnname() override {
        return branches[0]->returnname();
    }
};
#endif