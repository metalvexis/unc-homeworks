
#include <iostream>
#include <string>

#include "./MyStack/MyStack.h"
#include "PostFix.h"

using namespace std;

void testEval( std::string );

int main(){

  string testExpr1 = "123*";
  string testExpr2 = "123+4*";
  string testExpr3 = "123*+";
  string testExpr4 = "123*4";
  string testExpr5 = "+123*4";
  string testExpr6 = "123*+4";
  

  testEval( testExpr1 );
  testEval( testExpr2 );
  testEval( testExpr3 );
  testEval( testExpr4 );
  testEval( testExpr5 );
  testEval( testExpr6 );
 
  
  return 0;
}

void testEval( std::string testExpr ){
   cout << endl << "Expression: " << testExpr << endl;

  PostFix pf(testExpr);

  try{
    
    cout << "isValid: " << (pf.isValid()?"True":"False") << endl;
    cout << "eval: " << pf.eval();

  }catch(const char* e){
    cout << e;
  }
  
  

  cout << endl;
}