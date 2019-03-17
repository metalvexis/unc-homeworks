#include <string>

#include "./MyStack/MyStack.h"

using namespace std;

#ifndef _POSTFIX_
#define _POSTFIX_

class PostFix {
  private: 
    std::string _expression;
    MyStack stack;

    bool hasInvalidElem();
    // static bool isRPN(std::string);
    static bool isOperand(char);
    static bool isOperator(char);
  
  public:

    PostFix() {
      _expression = "";
    };
    
    PostFix( std::string expr ) { _expression = expr; };

    void setExpr( std::string expr ) { _expression = expr; };

    std::string eval();

    bool isValid();
};

#endif