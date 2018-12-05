/**
	BinGrayBin.cpp
		Convert binary code to Gray code and
		from Gray code to binary code using
		only <char>s
	@author zeph|nzer
	@website http://zephinzer.sg
**/
#include "BinGrayBin.h"

// uncomment #define TEST below to initiate testing functions
//#define TEST

int main(void) {
	_runTests();
	std::cout << "Enter Binary number : ";
	const char* input = getInput();
	const char* output = convertToGray(input);
	std::cout << "Converted Gray Code : " << output << std::endl;
	
	std::cout << "Enter Gray Code     : ";
	input = getInput();
	output = convertToBinary(input);
	std::cout << "Converted to Binary : " << output << std::endl;
}

/**
	-
	-
	Function bodies
	-
	-
**/

const char* getInput() {
	std::string input;
	std::cin >> input;
	return input.c_str();
}

const char* convertToBinary(const char* input) {
	std::stringstream output;
	// MSB is always the same
	output << input[MSB];
	char last = input[MSB];
	size_t inputLen = strlen(input);
	if(inputLen > 1) {
		for(size_t i = MSB + 1; i < inputLen; ++i) {
			// check next MSB, if 1, toggle, else no change
			if(input[i] == ONE) {
				last = NOT(last);
			} 
			output << last;
		}
	}
	return output.str().c_str();
}

const char* convertToGray(const char* input) {
	std::stringstream output;
	// msb is always the same
	output << input[MSB];
	// go through the remaining
	size_t inputLen = strlen(input);
	if(inputLen > 1) {
		for(size_t i = MSB; i < inputLen - 1; ++i) {
			// XOR the current and the next to get Gray Code
			output << XOR(input[i], input[i+1]);
		}
	}
	return output.str().c_str();
}

char NOT(char n) {
	if(n == ZERO) {
		return ONE;
	} else {
		return ZERO;
	}
}

char XOR(char n1, char n2) {
	int i1 = 0,
		i2 = 0;
	if(n1 == ZERO) i1 = 0;
	else if(n1 == ONE) i1 = 1;
	if(n2 == ZERO) i2 = 0;
	else if(n2 == ONE) i2 = 1;
	if( i1 + i2 == 1 ) return ONE;
	else return ZERO;
}


/**
	-
	-
	Test functions
	-
	-
**/
bool _runTests() {
	#ifdef TEST
		if(	!_XOR() ||
			!_NOT() ||
			!_convertToGray() ||
			!_convertToBinary()
			) {
			std::cout << "Test failed, exiting now." << std::endl;
			return false;
		}
	#endif
	return true;
}

bool _convertToGray() {
	if(strcmp("0000", convertToGray("0000")) != 0) {
		return false;
	} else if(strcmp("1000", convertToGray("1111")) != 0) {
		return false;
	} else if(strcmp("0111", convertToGray("0101")) != 0) {
		return false;
	} else if(strcmp("0", convertToGray("0")) != 0) {
		return false;
	} else if(strcmp("1", convertToGray("1")) != 0) {
		return false;
	} 
	return true;
}

bool _convertToBinary() {
	if(strcmp("0000", convertToBinary("0000")) != 0) {
		return false;
	} else if(strcmp("1010", convertToBinary("1111")) != 0) {
		return false;
	} else if(strcmp("0110", convertToBinary("0101")) != 0) {
		return false;
	} else if(strcmp("0", convertToBinary("0")) != 0) {
		return false;
	} else if(strcmp("1", convertToBinary("1")) != 0) {
		return false;
	} 
	return true;
}

bool _NOT() {
	if(NOT(ONE) != ZERO) {
		return false;
	} else if(NOT(ZERO) != ONE) {
		return false;
	}
	return true;
}

bool _XOR() {
	if(XOR(ZERO, ZERO) == ONE) {
		return false;
	} else if(XOR(ZERO, ONE) == ZERO) {
		return false;
	} else if(XOR(ONE, ZERO) == ZERO) {
		return false;
	} else if(XOR(ONE, ONE) == ONE) {
		return false;
	}
	return true;
}