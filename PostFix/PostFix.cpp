#include <string>
#include <iostream>

#include "PostFix.h"

using namespace std;

std::string PostFix::eval(){
  return "0";
}

bool PostFix::isValid(){
  cout << endl;
  // Numerics : 48 - 57
  // Operators:
  // 42   : *
  // 43   : +
  // 45   : -
  // 47   : /
  
  bool isValid = true;

  // Check string for invalid element
  for(  std::string::iterator strIter = _expression.begin(); strIter != _expression.end(); strIter++){
    int decVal = *strIter;
    bool isNumeric = false;
    bool isOperator = false;

    isNumeric = decVal>=48 && decVal<=57;

    switch (decVal){
      case 42:
      case 43:
      case 45:
      case 47:
        isOperator = true;
        break;
      default:
        isOperator = false;
        break;
    }
    
    // cout << decVal << " : " << ( isNumeric || isOperator ) << endl;
    if( !(isNumeric || isOperator) ){
      isValid = isNumeric || isOperator;
      break;
    }
  }

  return isValid;
  // simulated eval to check if in postfix format
  
}