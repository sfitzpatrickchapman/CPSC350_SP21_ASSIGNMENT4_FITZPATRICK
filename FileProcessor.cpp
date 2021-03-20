// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This file implements the file processor class for the DNA complementer

#include "FileProcessor.h"

/*--------------------File Processor Implementation--------------------*/
FileProcessor::FileProcessor() {}

FileProcessor::~FileProcessor() {}

void FileProcessor::processFile(string inputFile) {
	DNAComplement DNA; //instantiate class with processor
	string textHolder; //stack pushes chars from here
	fstream readFile;
	fstream writeFile;

	readFile.open(inputFile, ios::in);

	if (readFile.is_open()) {
		writeFile.open("dnaoutput.txt", ios::out);

		/* Wile readFile still has lines to be read, assign line contents
		to textHolder, push those to a stack, calculate, and write */
		while (getline(readFile, textHolder)) {
			GenStack<char>* finalDNA = new GenStack<char>();

			/* For each char in textHolder, push to stack as uppercase */
			for (int i = 0; i < textHolder.length(); i++)
				finalDNA->push(toupper(textHolder[i]));

			/* Compute the DNA and reverse it so it write properly */
			finalDNA = DNA.computeComplement(finalDNA);
			finalDNA->reverseStack();

			/* Write all contents to dnaoutput while popping */
			while (finalDNA->stackSize != 0)
				writeFile << finalDNA->pop();
			writeFile << endl;

			delete finalDNA;
		}

		/* Successful file read/write message */
		cout << "Your DNA reverse compelement(s) successfully";
		cout << " outputted to \"dnaoutput.txt\"!" << endl << endl;
	}
	else { //invalid file handling
		cout << "ERROR #6: Invalid input. The file may spelled ";
		cout << "improperly or without \".txt\"." << endl << endl;
		exit(6);
	}

	readFile.close();
	writeFile.close();
}
