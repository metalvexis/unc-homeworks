#include "MyStack.h"

#include <iostream>

using namespace std;

void MyStack::initStack(int size){ 
  ptrStack = new char[size];
  stackSize = size;
  topElemIdx = 0;
}

bool MyStack::isEmpty(){
  return topElemIdx==0;
}

bool MyStack::isFull(){
  return topElemIdx+1 == stackSize;
}

void MyStack::print(){
  for(int _i = 0; _i<=topElemIdx; _i++){
    cout<< ptrStack[_i];
  }
  cout << endl;
}

char MyStack::top(){
  return ptrStack[topElemIdx];
}

void MyStack::pop(){
  if( !isEmpty() ) topElemIdx--;
}

void MyStack::push(char val){
  if( isFull() ) expandStack();

  topElemIdx++;
  ptrStack[ topElemIdx ] = val;
}

void MyStack::expandStack(){
  int newSize = stackSize*2;
  
  char * ptrTmp = new(nothrow) char[newSize];
  
  for(int _i=0; _i<=topElemIdx; _i++){
    ptrTmp[_i] = ptrStack[_i];
  }

  ptrStack = ptrTmp;
  stackSize = newSize;
}