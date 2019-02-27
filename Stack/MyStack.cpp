#include "MyStack.h"

#include <iostream>

using namespace std;

bool MyStack::isEmpty(){
  return topElemIdx==0;
}

bool MyStack::isFull(){
  int size = sizeof(ptrStack)/sizeof(*ptrStack);
  return topElemIdx-1 == size;
}

void MyStack::print(){
  for(int _i = 0; _i<topElemIdx; _i++){
    cout<< ptrStack[_i];
  }
}

char MyStack::top(){
  return ptrStack[topElemIdx-1];
}

void MyStack::pop(){
  if( !isEmpty() ) topElemIdx--;
}

void MyStack::push(char val){
  // cout << "isFull: " << isFull() << endl;
  // cout << "Pushing: " << val << " - " << "isFull: " << isFull() << endl;

  if( isFull() ){
    // cout << "Resizing ..." << endl;
    int newSize = topElemIdx*2;
    char * ptrTmp = new(nothrow) char[newSize];
    
    for(int _i=0; _i<topElemIdx; _i++){
      ptrTmp[_i] = ptrStack[_i];
    }
    
    ptrStack = ptrTmp;
  }

  ptrStack[ topElemIdx ] = val;
  topElemIdx++;
}