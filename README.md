# Assignment 4: Having fun with stacks
This program takes "RPN" or "DNA" as a command line argument. If the user chooses
RPN, they will be prompted to enter inputs until the wish to stop. The program then
calculates the inputs and displays the answer to the console. If the user chooses
DNA, they will be prompted for an input file name. After entering it, the program
will read each line and write a reverse complement of the DNA to a file called
"dnaoutput.txt". Only DNA letters, lower or uppercase, will be written.


## Identifying Information
* Name: Scott Fitzpatrick
* Student ID: 2328196
* Email: sfitzpatrick@chapman.edu
* Course: CPSC 350
* Assignment: 4

## Source Files  
* main.cpp
* StackNode.h
* GenStack.h
* RPNCalc.h
* RPNCalc.cpp
* DNAComplement.h
* DNAComplement.cpp
* FileProcessor.h
* FileProcessor.cpp

## References
* Data Structures ZyBooks Textbook
* PFN education: https://www.youtube.com/watch?v=84BsI5VJPq4
* isdigit: http://www.cplusplus.com/reference/cctype/isdigit/
* length(): https://www.w3schools.com/cpp/cpp_strings_length.asp
* Casting: https://www.bitdegree.org/learn/string-to-int-c-plus-plus
* Exception Handling https://www.geeksforgeeks.org/exception-handling-c/
* Command line arguments: https://www.cplusplus.com/forum/beginner/47996/
* Reverse Polish notation: https://en.wikipedia.org/wiki/Reverse_Polish_notation
* int or string: https://www.geeksforgeeks.org/program-check-input-integer-string/
* Stacks: https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
* RPN Stacks: https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/

## Build Insructions
* g++ *.cpp

## Execution Instructions
* ./a.out RPN
* ./a.out DNA
