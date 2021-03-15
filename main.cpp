#include <iostream>
#include "GenStack.h"
#include "StackNode.h"
using namespace std;

int main(int argc, char** argv) {
  cout << "Running..." << endl;

  GenStack<int>* myStack = new GenStack<int>();
  myStack->push(4);
  myStack->push(3);
  myStack->push(2);
  myStack->push(1);
  myStack->printStack();
  myStack->pop();
  myStack->pop();
  myStack->pop();
  myStack->printStack();

  cout << "Done." << endl;
}

/*
TODO:
-implement destructors
-use proper error handling

*/
