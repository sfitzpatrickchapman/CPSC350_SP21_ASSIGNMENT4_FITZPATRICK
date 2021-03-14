#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

/*----------------------------------Header----------------------------------*/
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

/*------------------Constructor/Desctructor Implementation------------------*/
template <class T>
StackNode<T>::StackNode() {}

template <class T>
StackNode<T>::StackNode(T newData) {
	data = newData;
	next = 0; //will be changed once node is stacked
}

template <class T>
StackNode<T>::~StackNode() { //TODO: check if this is okay
	data = 0;
	next = 0;
}

#endif