// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This file is the header for the DNA complementer class

#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H

#include "StackNode.h"
#include "GenStack.h"
#include <iostream>
using namespace std;

/*-------------------------Header-------------------------*/
class DNAComplement {
public:
	/* Constructors & destructor */
	DNAComplement();
	~DNAComplement();

	/* Core function */
	GenStack<char>* computeComplement(GenStack<char>* DNA);
};

#endif
