
#include <iostream>
#include <string>

#include "./MyStack/MyStack.h"
#include "PostFix.h"

using namespace std;

void testEval( std::string );

int main(){

  std::string testExpr [] = {
    
    "623*",   // dangling input: 6 
    "623+4*", // dangling input: 6
    "123*+",  // valid
    "123-/",  // valid
    "123-4/", // valid
    "123/-",  // valid

    // 3 * 2 ? 4
    "123*4",
    // ? + ?
    "+123*4",
    // 1 + ?
    "1+23*4",
    // divide by zero
    "30/2*",
  };
  
  for(auto i = 0; i < 10; i++)
  {
    testEval( testExpr[i] );
  }
 
  
  return 0;
}

void testEval( std::string testExpr ){
   cout << endl << "Expression: " << testExpr << endl;

  PostFix pf(testExpr);

  try{
    cout << "isValid: " << (pf.isValid()?"True":"False") << endl;
    cout << "eval: " << pf.eval();
  }catch(const char* e){
    cerr << e;
  }
  
  

  cout << endl;
}