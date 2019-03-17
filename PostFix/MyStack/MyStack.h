#ifndef _MY_STACK_
#define _MY_STACK_

class MyStack {
  private: 
    double * ptrStack;
    
    int topElemIdx;

    int stackSize;
  
  public:

    MyStack() { initStack(10); };

    ~MyStack() { delete[] ptrStack; };
    
    MyStack(int size) { initStack(size); };

    void initStack(int size);

    bool isEmpty();

    bool isFull();

    double top();

    int topIdx();

    void print();

    void push(double);

    void pop();

    void expandStack();

    void clear();
};

#endif