#ifndef _MY_STACK_
#define _MY_STACK_

class MyStack {
  private: 
    char * ptrStack;
    
    int topElemIdx;
  
  public:

    MyStack() { initStack(10); };

    ~MyStack() { delete[] ptrStack; };
    
    MyStack(int size) { initStack(size); };

    void initStack(int size){ ptrStack = new char[size]; topElemIdx = 0; }

    bool isEmpty();

    bool isFull();

    char top();

    void print();

    void push(char);

    void pop();    
};

#endif