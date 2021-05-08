#ifndef ast_char_hpp
#define ast_char_hpp

#include "ast_node.hpp"

class charType // a&&b
    : public Node
{
public:
    charType(const std::string& _id)
    {}

    std::string type = "CharType";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return NULL;
    }

    virtual float evaluate() {
        return 0;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class sizeofsmtg // a&&b
    : public Node
{
public:
    sizeofsmtg(NodePtr exp2)
    {
    branches.push_back(exp2);
    }

    std::string type = "Sizeof";
    virtual std::string returntype() override {
            return type;

    }

    virtual NodePtr getbranch(int x) override {
        return branches[0];
    }

    virtual float evaluate() {
        return 0;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};
#endif
