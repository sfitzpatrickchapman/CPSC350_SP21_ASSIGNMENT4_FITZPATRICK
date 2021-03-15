#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "StackNode.h"
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
    void printStack();

private:
    StackNode<T>* top;
    size_t stackSize;
};

/*--------------------------Function Implementation--------------------------*/
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
    top = newItem;

    stackSize++;
}

template <class T>
T GenStack<T>::pop() {
  if (stackSize == 0) { //if stack empty
    cout << "ERROR: Stack is empty. Nothing to pop." << endl;
    exit(1);
  }

  T temp = top; //remember top data before deleting
  top = top->next; //set the following node to top
  delete top; //delete the top
  stackSize--; //decrement stack size
  return temp; //return the popped data
}

template <class T>
T GenStack<T>::peek() {
  if (stackSize == 0) { //if stack empty
    cout << "ERROR: Stack is empty. Nothing to peek." << endl;
    exit(1);
  }

  return top;
}

template <class T>
void GenStack<T>::printStack() {
  StackNode<T>* temp;

  if (stackSize == 0) { //if stack empty
    cout << "ERROR: Stack is empty. Nothing to peek." << endl;
    exit(1);
  }
  else {
    temp = top;
    while (temp != 0) {
      cout << temp->data << "-> ";
      temp = temp->next;
    }
  }
}

#endif
