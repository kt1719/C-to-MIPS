#ifndef ast_node_hpp
#define ast_node_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

class Node;

typedef Node* NodePtr;

class Node
{
public:
    virtual ~Node()
    {}

    //! Evaluate the tree using the given mapping of variables to numbers
    //virtual double evaluate() const = 0;
    std::vector<NodePtr> branches;
    std::string type;

    virtual std::string returntype() = 0;
    virtual NodePtr getbranch(int x) = 0;
    virtual float evaluate() = 0;
    virtual std::vector<std::string> returnname() = 0;
    virtual std::string name() = 0;
    virtual void replacearg(NodePtr x) = 0;
};


#endif
