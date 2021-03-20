// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This is a template class file for StackNodes within GenStack

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

/*---------------------------Header---------------------------*/
template <class T>
class StackNode {
public:
	/* Constructors & Destructor */
	StackNode();
	StackNode(T newData);
	~StackNode();

	/* Variables/Pointers */
	T data;
	StackNode* next;
};

/*-----------Constructor/Desctructor Implementation-----------*/
template <class T>
StackNode<T>::StackNode() {}

template <class T>
StackNode<T>::StackNode(T newData) {
	data = newData;
	next = 0;
}

template <class T>
StackNode<T>::~StackNode() {}

#endif
