#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
using namespace std;

/*----------------------------------Header----------------------------------*/
template <class T>
class GenStack {
public:
    /* Constructors & destructor */
    GenStack();
    ~GenStack();

    /* Core functions */
    void push(T newItem);
    T pop();
    T peek();

    /* Helper functions */
    void printStack(bool printLink);

private:
    StackNode<T>* top;
    size_t stackSize;
};

/*-----------------------Core Function Implementation-----------------------*/
template <class T>
GenStack<T>::GenStack() {
    stackSize = 0;
    top = 0;
}

template <class T>
GenStack<T>::~GenStack() {
    // manually delete/garbage collect
    // while loop
}

template <class T>
void GenStack<T>::push(T newItem) {
    newItem->next = top;
    top = lksdjl;

    stackSize++;
}

#endif