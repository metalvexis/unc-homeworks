
#include <iostream>
#include <string>

#include "./MyStack/MyStack.h"
#include "PostFix.h"

using namespace std;

int main(){

  string testExpr = "12+4-";
  cout << "Input expression: " << testExpr << endl;

  PostFix pf(testExpr);
  cout << "PostFix isValid: " << pf.isValid() << endl;
  cout << "PostFix Eval: " << pf.eval();

  cout << endl;
  
  return 0;
}