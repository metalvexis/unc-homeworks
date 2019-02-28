
#include <iostream>
#include <string>

#include "MyStack.h"

using namespace std;

int main(){

  string testInput = "1234567890";

  cout << "Input string: " << testInput << endl;
  MyStack stack(3);

  for(int _i=0; _i<testInput.length(); _i++){
    stack.push(testInput[_i]);
  }

  cout << "Print Stack: ";
  stack.print();
  cout << "Top: " << stack.top();
  cout << endl;

  int popItemCount = 20;

  cout << "Popping " << popItemCount << " Items" << endl;

  for(int _i=0; _i<popItemCount; _i++){
    stack.pop();
  }

  cout << "Print Stack: ";
  stack.print();
  cout << "Top: " << stack.top();
  cout << endl;
  
  return 0;
}