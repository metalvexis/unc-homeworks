#include <string>

#include "./MyStack/MyStack.h"

using namespace std;

#ifndef _POSTFIX_
#define _POSTFIX_

class PostFix {
  private: 
    std::string _expression;
    MyStack stack;
  
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