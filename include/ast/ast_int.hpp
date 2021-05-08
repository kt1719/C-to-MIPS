#ifndef ast_int_hpp
#define ast_int_hpp

#include "ast_node.hpp"

class intType // a&&b
    : public Node
{
public:
    intType(const std::string& _id)
    {}
    std::string type = "inttype";
    virtual std::string returntype() override {
        return type;
    }
    virtual void replacearg(NodePtr x) override {}
    virtual NodePtr getbranch(int x) override {
        return NULL;
    }

    virtual float evaluate(){
        return 0;
    }
    virtual std::vector<std::string>  returnname() override {
        return std::vector<std::string>();
    }

    virtual std::string name() override {
        return "";
    }
};

class voidType // a&&b
: public Node
{
public:
  voidType(const std::string& _id)
  {}

    std::string type = "VoidType";
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

  class unsignedType // a&&b
      : public Node
  {
  public:
      unsignedType(const std::string& _id)
      {}

      std::string type = "UnsignedType";
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

  class floatType // a&&b
      : public Node
  {
  public:
      floatType(const std::string& _id)
      {}

      std::string type = "FloatType";
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

  class doubleType // a&&b
      : public Node
  {
  public:
      doubleType(const std::string& _id)
      {}

      std::string type = "DoubleType";
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
  #endif
