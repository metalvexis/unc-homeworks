#ifndef _MY_STACK_
#define _MY_STACK_

class MyStack {
  private: 
    char * ptrStack;
    
    int topElemIdx;

    int stackSize;
  
  public:

    MyStack() { initStack(10); };

    ~MyStack() { delete[] ptrStack; };
    
    MyStack(int size) { initStack(size); };

    void initStack(int size);

    bool isEmpty();

    bool isFull();

    char top();

    void print();

    void push(char);

    void pop();

    void expandStack();
};

#endif