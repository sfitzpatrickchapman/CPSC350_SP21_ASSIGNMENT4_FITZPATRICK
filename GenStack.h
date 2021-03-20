// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This is a template class file for the essential singly-linked list stack

#ifndef GENSTACK_H
#define GENSTACK_H

#include "StackNode.h"
#include <iostream>
using namespace std;

/*---------------------------------Header---------------------------------*/
template <class T>
class GenStack {
public:
    /* Constructors & destructor */
    GenStack();
    ~GenStack();

    /* Core functions */
    void push(T newItem);
    void inputPFN();
    T pop();
    T peek();
    void reverseStack();

    /* Helper function */
    void printStack();

    /* Variables/Pointers */
    StackNode<T>* top;
    size_t stackSize;
};

/*-------------------------Function Implementation-------------------------*/
template <class T>
GenStack<T>::GenStack() {
    stackSize = 0;
    top = 0;
}

template <class T>
GenStack<T>::~GenStack() {
    StackNode<T>* curr = top;

    /* Loop through stack and delete each node */
    while (curr != 0) {
        StackNode<T>* temp = curr->next; //remember next top
        delete curr; //delete current top
        curr = temp; //recall top's next to set as new top
    }
}

template <class T>
void GenStack<T>::push(T newItem) {
    StackNode<T>* newNode = new StackNode<T>(newItem);

    newNode->next = top; //set new top's next pointer
    top = newNode; //officially set new node as top
    stackSize++; //increment the stack size
}

template <class T>
void GenStack<T>::inputPFN() { //strings used in case of 2+ digits
    /* Prompt for inputs or stop command */
    cout << "\nPlease enter your PFN equation in order below." << endl;
    cout << "Enter an operator, integer, or 'stop' to stop: " << endl;

    int counter = 1; //will be used for numbering "Input #:"

    /* Input numbers or operators (as strings for now) for the postfix
    equation until the user enters stops. If the input is invalid,
    errors and warnings will be thrown from elsewhere */
    while (true) {
        /* Prompt and input for individual element */
        string PFNinput;
        cout << "  Input " << counter << ": ";
        cin >> PFNinput;

        // if proper input
        if (PFNinput == "+" || PFNinput == "-" || PFNinput == "*" ||
            PFNinput == "/" || PFNinput == "%" || isdigit(PFNinput[0])) {
            this->push(PFNinput);
            counter++;
        }
        else if (PFNinput == "stop") //if user wishes to stop
            break;
        else { //if invalid input (not number or operator)
            cout << "    " << PFNinput << " has not been added!" << endl;
            cout << "    Inputs must be operators or integers." << endl;
            cout << "    Examples: \"3\", \"43\", \"*\", \"%\" "<< endl;
        }
    }
}

template <class T>
T GenStack<T>::pop() {
    try {
        if (stackSize == 0)
            throw 1;

        T temp = top->data; //remember data of top
        top = top->next; //set new top to the following
        stackSize--; //decrement stackSize
        return temp; //return recalled data
    }
    catch (int x) { //if stack empty throw error and possible hint
        cout << "ERROR #" << x;
        cout << ": Cannot pop() an empty stack." << endl;
        cout << "-If this occured after inputting an PFN equation, make ";
        cout << "sure there weren't too many operators." << endl << endl;
        exit(x);
    }
}

template <class T>
T GenStack<T>::peek() {
    try {
        if (stackSize == 0)
            throw 2;

        return top->data;
    }
    catch (int x) { //if stack empty give error
        cout << "ERROR #" << x;
        cout << ": Cannot peek() an empty stack." << endl;
        exit(x);
    }
}

template <class T>
void GenStack<T>::printStack() { //pretty print (for testing)
    try {
        if (stackSize == 0)
            throw 3;

        StackNode<T>* curr = top; //initialize current node to print
        cout << "\n--STACK--" << endl; //header
        /* Prints stack (on multiple lines) to visualize */
        while (curr != 0) {
            if (curr == top) //label top element
                cout << "Top: ";
            else //label body elements
                cout << "Bod: ";

            /* Print current node and then set as next */
            cout << curr->data << endl;
            curr = curr->next;
        }
        cout << endl;
    }
    catch (int x) {
        cout << "ERROR #" << x;
        cout << ": Cannot printStack() an empty stack." << endl;
    }
}

template <class T>
void GenStack<T>::reverseStack() {
    /* Deletes original stack and makes a reverse copy and
    saves the header and stackSize of that for the class */
    GenStack<T>* reversedStack = new GenStack<T>();

    /* Re-stacks which reverses copy while deleting original */
    while (stackSize != 0)
        reversedStack->push(this->pop());

    /* Reset class stacksize & reassign top pointer */
    this->stackSize = reversedStack->stackSize;
    this->top = reversedStack->top;
}

#endif
