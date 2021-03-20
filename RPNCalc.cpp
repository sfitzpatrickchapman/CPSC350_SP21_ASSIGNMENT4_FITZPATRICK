// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This is the RPNCalc file that implements the calculator and helper function

#include "RPNCalc.h"

/*-----------------------RPN Calculator Implementation-----------------------*/
RPNCalc::RPNCalc() {}

RPNCalc::~RPNCalc() {}

int RPNCalc::RPNCalculate(GenStack<string>* PFequation) { //PF for postfix
	GenStack<int>* intStack = new GenStack<int>(); //where the magic happens

	/* Until the postfix notation equation stack is empty, convert string
	numbers to integers and add to intStack. If the stack element is an
	operator, preform that operation on the two top elements of intStack */
	while (PFequation->stackSize != 0) {
		if (isOperator(PFequation->peek())) { //if operator
			/* Prepare operation on top 2 vals & remove from stack */
			int val1 = intStack->pop();
			int val2 = intStack->pop();

			/* Find the operator type, caluclate, and push to stack */
			char operand = PFequation->pop()[0]; //convert to char for switch
			switch (operand) {
			case '+':
				intStack->push(val2 + val1); break;
			case '-':
				intStack->push(val2 - val1); break;
			case '*':
				intStack->push(val2 * val1); break;
			case '/':
				intStack->push(val2 / val1); break;
			case '%':
				intStack->push(val2 % val1); break;
			}
		}
		else //if integer
			intStack->push(stoi(PFequation->pop())); //add as int to stack
	}
	if (intStack->top->next != 0) { //if too many operands warn user
		cout << "WARNING: There were too many integers in your postfix ";
		cout << "equation! The extras will be ignored." << endl;
	}

	return intStack->pop(); //intStack should only contain answer
}

bool RPNCalc::isOperator(string stackItem) {
	/* Return true if a string represents a single operator */
	if (stackItem == "+" || stackItem == "-" || stackItem == "*" || stackItem == "/" || stackItem == "%")
		return true;
	return false;
}
