// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This is the RPNCalc class header file for the calculator

#ifndef RPNCALC_H
#define RPNCALC_H

#include "StackNode.h"
#include "GenStack.h"
#include <iostream>
#include <string>
using namespace std;

/*-------------------------Header-------------------------*/
class RPNCalc {
public:
	/* Constructors & destructor */
	RPNCalc();
	~RPNCalc();

	/* Core function */
	int RPNCalculate(GenStack<string>* postfixEquation);

private:
	/* Helper Function */
	bool isOperator(string stackItem);
};

#endif
