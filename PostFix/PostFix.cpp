#include <string>
#include <iostream>

#include "PostFix.h"

using namespace std;

std::string PostFix::eval(){
  stack.clear();

  for(  std::string::iterator strIter = _expression.begin(); 
        strIter != _expression.end(); 
        strIter++ ) {

    bool isOperand = PostFix::isOperand( *strIter );
    bool isOperator = PostFix::isOperator( *strIter );

    if( isOperand ){
      
      stack.push( double(*strIter-48) );
      
      if( strIter+1 == _expression.end() ){
        throw "operator expected";
      }
    
    } else if ( isOperator ){
      double operand1 = 0;
      double operand2 = 0;
      double result = 0;

      if( stack.isEmpty() ){
        throw "not rpn (prefix)";
      };
      
      operand1 = stack.top();
      stack.pop();

      if( stack.isEmpty() ){
        if( strIter+1 == _expression.end() ){
          throw "two operands expected";
        }else{
          throw "not rpn (infix)";
        }
      };

      operand2 = stack.top();
      stack.pop();

      switch ( *strIter ){
        case 42: // *
          result = operand2 * operand1;
          break;
        case 43: // +
          result = operand2 + operand1;
          break;
        case 45: // -
          result = operand2 - operand1;
          break;
        case 47: // /
          if(operand1==0) throw "Divide by zero";
          result = operand2 / operand1;
          
          break;
        default:
          // unlikely to happen
          // but if it did, replace your RAM
          result = 0; 
          break;
      }

      stack.push( result );
    }else{
      throw "unexpected element";
    }
  }

  return std::to_string(stack.top());
}

bool PostFix::isValid(){
  // Operands : 48 - 57
  // Operators:
  // 42   : *
  // 43   : +
  // 45   : -
  // 47   : /
  try {
    eval();
  }catch( const char * err ){
    return false;
  }
  return true;
}

bool PostFix::isOperand(char x){
  return x >= 48 && x <= 57;
}

bool PostFix::isOperator(char x){
  switch (x){
    case 42:
    case 43:
    case 45:
    case 47:
      return true;
      break;
    default:
      return false;
      break;
  }
}