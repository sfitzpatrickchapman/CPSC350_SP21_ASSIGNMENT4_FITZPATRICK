// Scott Fitzpatrick
// 2328196
// sfitzpatrick@chapman.edu
// CPSC 350-01
// Assignment 4: Having fun with stacks :)
// This file contains the implementation function for the DNA complementer

#include "DNAComplement.h"

/*----------------------DNAComplement Implementation----------------------*/
DNAComplement::DNAComplement() {}

DNAComplement::~DNAComplement() {}

GenStack<char>* DNAComplement::computeComplement(GenStack<char>* DNA) {
	GenStack<char>* rcDNA = new GenStack<char>(); //reversed-complemented

	/* While the original DNA stack isn't null, find what the top data is
	and push desginated complementary letters to the new complemented DNA
	stack. Pops original DNA every loop and ignores all other chars */
	while (DNA->stackSize != 0) {
		char DNAdata = DNA->pop();

		if (DNAdata == 'A')
			rcDNA->push('T');
		else if (DNAdata == 'T')
			rcDNA->push('A');
		else if (DNAdata == 'G')
			rcDNA->push('C');
		else if (DNAdata == 'C')
			rcDNA->push('G');
	}

	delete DNA;
	return rcDNA;
}
