#include "MyStack.h"

#include <iostream>

using namespace std;

void MyStack::initStack(int size){ 
  ptrStack = new double[size];
  stackSize = size;
  topElemIdx = 0;
}

bool MyStack::isEmpty(){
  return topElemIdx <= 0;
}

bool MyStack::isFull(){
  return topElemIdx+1 == stackSize;
}

void MyStack::print(){
  for(int _i = 0; _i<topElemIdx; _i++){
    cout<< ptrStack[_i];
  }
  cout << endl;
}

int MyStack::topIdx(){
  return topElemIdx-1;
}

double MyStack::top(){
  if( isEmpty() ) return double(0);
  return ptrStack[topElemIdx-1];
}

void MyStack::pop(){
  if( !isEmpty() ) topElemIdx--;
}

void MyStack::push(double val){
  if( isFull() ) expandStack();

  ptrStack[ topElemIdx ] = val;
  topElemIdx++;
}

void MyStack::expandStack(){
  int newSize = stackSize*2;
  
  double * ptrTmp = new(nothrow) double[newSize];
  
  for(int _i=0; _i<=topElemIdx; _i++){
    ptrTmp[_i] = ptrStack[_i];
  }

  ptrStack = ptrTmp;
  stackSize = newSize;
}

void MyStack::clear(){
  delete[] ptrStack;
  initStack(10);
}