// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This is the main file that runs either the RPN or DNA program

#include "GenStack.h"
#include "StackNode.h"
#include "RPNCalc.h"
#include "DNAComplement.h"
#include "FileProcessor.h"
#include <iostream>
#include <string>
using namespace std;

/*----------------------------Main----------------------------*/
int main(int argc, char** argv) {
	if (string(argv[1]) == "RPN") {
		/* Intantiate RPN calculator class and empty stack */
		RPNCalc calc;
		GenStack<string>* RPNequation = new GenStack<string>();

		/* Input and re-order for calculator */
		RPNequation->inputPFN();
		RPNequation->reverseStack();

		/* Calculate and print */
		int answer = calc.RPNCalculate(RPNequation);
		cout << "The answer to your postfix equation is: ";
		cout << answer << endl << endl;

		delete RPNequation;
	}
	else if (string(argv[1]) == "DNA") {
		FileProcessor process;
		string inputFile;

		cout << "\nPlease enter your input file: ";
		cin >> inputFile;

		process.processFile(inputFile); //deletes stack in method
	}
	else {
		cout << "ERROR #5: Invalid command line argument. ";
		cout << "Please enter \"RPN\" or \"DNA\"." << endl;
		exit(5);
	}

	return 0;
}
