#ifndef ast_param_hpp
#define ast_param_hpp

#include "ast_node.hpp"

class param_list // if (expr) {statement}
    : public Node
{

public:
    param_list(NodePtr paramexp)
    {
      branches.push_back(paramexp);
      branches.push_back(NULL);
    }

    param_list(NodePtr paramexp, NodePtr paramexp2)
    {
      branches.push_back(paramexp);
      branches.push_back(paramexp2);
    }

    std::string type = "ParamList";
    virtual std::string returntype() override {
        return type;
    }

    virtual NodePtr getbranch(int x) override {
        return branches[x];
    }
    virtual void replacearg(NodePtr x) override {}

    virtual float evaluate() {
        if (branches[0] == NULL && branches[1] == NULL) {
            return 0;
        }
        else if (branches[0] == NULL) {
            return 1;
        }
        else if (branches[1] == NULL) {
            return 1;
        }
        if (branches[0]->returntype() == "Variable" && branches[1]->returntype() == "Variable") {
            return 2;
        }
        else {
            if (branches[0]->returntype() == "Variable") {
                float x = branches[1]->evaluate();
                return x + 1;

            }
            else if (branches[1]->returntype() == "Variable") {
                float x = branches[0]->evaluate();
                return x + 1;
            }
        }
    }

    virtual std::vector<std::string>  returnname() override
        ///////////
    {
        std::vector<std::string> x;
        if (branches[0] == NULL && branches[1] == NULL) {
            return x;
        }
        else if (branches[0] == NULL) {
            if (branches[1]->getbranch(0) != NULL) {
                if (branches[1]->getbranch(0)->returntype() == "FloatType") {
                    x.push_back(branches[0]->name() + "%");
                    return x;
                }
                else if (branches[1]->getbranch(0)->returntype() == "DoubleType") {
                    x.push_back(branches[0]->name() + "|");
                    return x;
                }
            }
            x.push_back(branches[1]->name());
            return x;
        }
        else if (branches[1] == NULL) {
            if (branches[0]->getbranch(0) != NULL) {
                if (branches[0]->getbranch(0)->returntype() == "FloatType") {
                    x.push_back(branches[0]->name() + "%");
                    return x;
                }
                else if (branches[0]->getbranch(0)->returntype() == "DoubleType") {
                    x.push_back(branches[0]->name() + "|");
                    return x;
                }
            }
            x.push_back(branches[0]->name());
            return x;
        }
        if (branches[0]->returntype() == "Variable" && branches[1]->returntype() == "Variable") {
            if (branches[0]->getbranch(0) != NULL) {
                if (branches[0]->getbranch(0)->returntype() == "FloatType") {
                    x.push_back(branches[0]->name() + "%");
                }
                else if (branches[0]->getbranch(0)->returntype() == "DoubleType") {
                    x.push_back(branches[0]->name() + "|");
                }
                else {
                    x.push_back(branches[0]->name());
                }
            }
            else {
                x.push_back(branches[0]->name());
            }
            if (branches[1]->getbranch(0) != NULL) {
                if (branches[1]->getbranch(0)->returntype() == "FloatType") {
                    x.push_back(branches[1]->name() + "%");
                }
                else if (branches[1]->getbranch(0)->returntype() == "DoubleType") {
                    x.push_back(branches[1]->name() + "|");
                }
                else {
                    x.push_back(branches[1]->name());
                }
            }
            else {
                x.push_back(branches[1]->name());
            }
            return x;
        }
        else {
            if (branches[0]->returntype() == "Variable") {
                if (branches[0]->getbranch(0) != NULL) {
                    if (branches[0]->getbranch(0)->returntype() == "FloatType") {
                        x.push_back(branches[0]->name() + "%");
                    }
                    else if (branches[0]->getbranch(0)->returntype() == "DoubleType") {
                        x.push_back(branches[0]->name() + "|");
                    }
                    else {
                        x.push_back(branches[0]->name());
                    }
                }
                else {
                    x.push_back(branches[0]->name());
                }
                std::vector<std::string> x2;
                x2 = branches[1]->returnname();
                x.insert(x.end(), x2.begin(), x2.end());
                return x;

            }
            else if (branches[1]->returntype() == "Variable") {
                if (branches[1]->getbranch(0) != NULL) {
                    if (branches[1]->getbranch(0)->returntype() == "FloatType") {
                        x.push_back(branches[1]->name() + "%");
                    }
                    else if (branches[1]->getbranch(0)->returntype() == "DoubleType") {
                        x.push_back(branches[1]->name() + "|");
                    }
                    else {
                        x.push_back(branches[1]->name());
                    }
                }
                else {
                    x.push_back(branches[1]->name());
                }
                std::vector<std::string> x2;
                x2 = branches[0]->returnname();
                x2.insert(x2.end(), x.begin(), x.end());
                return x2;
            }
        }
    }



    
    virtual std::string name() override { return ""; }
};

#endif
