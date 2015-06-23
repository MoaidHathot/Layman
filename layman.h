//#pragma once

#ifndef _Layman_Header_0xCAFEBABE
#define _Layman_Header_0xCAFEBABE

#include <iostream>
#include "Arrays.h"
#include "Utilities.h"

class Letter{

	char letter;
	bool letterValue;

public:
	Letter( char _letter = 0, bool _letterValue = 0 ):letter(_letter),letterValue(_letterValue){ }

	char getLetter(){ return letter; }
	char getValue(){ return letterValue; }
};

typedef bool (*OperatorAction)( Array<bool>& ); 

class Operator{

	int numberOfArguments;
	OperatorAction action;

public:
	Operator( int _numberOfArguments = 0, OperatorAction _action = NULL ):numberOfArguments(_numberOfArguments), action(_action){ }

	int argumentsCount(){ return numberOfArguments; }
	OperatorAction operatorAction(){ return action; }
};

typedef map<char,Letter> LettersMap;
typedef map<char, Operator> OperatorsMap;


bool layman( std::string string, OperatorsMap& operators, LettersMap& letters );

#endif