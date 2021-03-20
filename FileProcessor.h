// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This is the header file for the DNA file processor

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

/*-------------File Processor Header-------------*/
#include "DNAComplement.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileProcessor {
public:
	FileProcessor();
	~FileProcessor();
	void processFile(string inputFile);
};

#endif
