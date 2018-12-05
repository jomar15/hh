/**
	BinGrayBin.h
		- header file for BinGrayBin.cpp
		Convert binary code to Gray code and
		from Gray code to binary code using
		only <char>s
	@author zeph|nzer
	@website http://zephinzer.sg
**/
#include <iostream>
#include <string>
#include <sstream>

#define ZERO	'0'
#define ONE		'1'
#define MSB 	0

/**
	Gets input string and churns out 
	const char* structure
**/
const char* getInput();
/**
	Converts a string consisting of '1's and '0's (in Binary Code)
	into the equivalent Gray Code in '1's and '0's
**/
const char* convertToGray(const char* input);
/**
	Converts a string consisting of '1's and '0's (in Gray Code)
	into the equivalent Binary Code in '1's and '0's
**/
const char* convertToBinary(const char* input);
/**
	XOR operator function
	truth table
	n1	n2	q
	0	0	0
	0	1	1
	1	0	1
	1	1	0
**/
char XOR(char n1, char n2);
/**
	NOT operator function
	truth table
	n	q
	0	1
	1	0
**/
char NOT(char n);

// test functions corresponding to above names
bool _convertToGray();
bool _convertToBinary();
bool _NOT();
bool _XOR();