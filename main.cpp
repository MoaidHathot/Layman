/**
	Programmed By : Moaid Hathot
**/
#include <iostream>
#include <stdio.h>
//#include "Arrays.h"
#include "Arrays.cpp"
#include "layman.h"
#include "Utilities.h"
#include <map>

using std::map;
using std::cout;
using std::endl;
using std::string;

bool dragging( Array<bool>& arguments ){

	bool src = arguments[0];
	bool toDrag = arguments[1];

	if( src )
		return toDrag;

	return true;
}

bool not( Array<bool>& arguments ){

	return !arguments[0];
}

void promptMainMenu();
void handleMainMenu( bool *keepGoing, OperatorsMap& operators, LettersMap& letters );
int readInteger( FILE *file, int start, int end);
void evaluateExpression( OperatorsMap& operators, LettersMap& letters );
void insertDefaultLetters( LettersMap& letters );
void insertDefaultOperators( OperatorsMap& operators );
void inputLetters( LettersMap& letters );

int main( int length, char *params ){

	OperatorsMap operators;
	LettersMap letters;

	insertDefaultOperators( operators );
	insertDefaultLetters( letters );


	bool keepGoing = true;

	do{
	
		promptMainMenu();
		handleMainMenu( &keepGoing, operators, letters );

		WaitForResponse;
		system( "cls" );

	}while( keepGoing );

	return 0;
}

void handleMainMenu( bool *keepGoing, OperatorsMap& operators, LettersMap& letters ){

	int input = readInteger( stdin, 1, 4 );

	if( 1 == input ){

		evaluateExpression( operators, letters );
	}
	else if( 2 == input ){

		inputLetters( letters );
	}
	else if( 3 == input ){

		letters.clear();
		insertDefaultLetters( letters );

		cout<<"\nAll letters cleared. t,T,f,F restored.";
	}
	else if( 4 == input ){

		*keepGoing = false;
	}
}

void promptMainMenu(){

	cout<<"1. Evaluate an expression."<<endl;
	cout<<"2. Add Letters."<<endl;
	cout<<"3. Remove All Letters."<<endl;
	cout<<"4. Quit."<<endl;
}
void inputLetters( LettersMap& letters ){

	cout<<"\nEnter <letter> <value>.";
	cout<<"\n<letter> is a letter from a-z and <value> is \"t\" or \"f\".";
	cout<<"\nLetters t and T already inserted as true, f and F as false.";
	cout<<"\nYou may change that if you want.";
	cout<<"\nNon a-z letters will be ignored.";
	cout<<"\npress 0 at least once in a row to stop.";
	cout<<"\n\nBegin:"<<endl;

	char letter = 0, val = 0;

	while( !fflush(stdin) && 2 == scanf(" %c %c", &letter, &val ) && letter != '0' && val != '0'){

		char captial, small;
		bool ignore = false;
		bool booleanValue;

		if( letter >= 'a' && letter <= 'z' ){

			small = letter;
			captial = (letter - 'a') + 'A';
		}
		else if( letter >= 'A' && letter <= 'Z' ){

			captial = letter;
			small = (letter - 'A') + 'a';
		}
		else{

			ignore = true;
		}

		if( val == 't' || val == 'T' )
			booleanValue = true;
		else if( val == 'f' || val == 'F' )
			booleanValue = false;
		else
			ignore = true;

		if( false == ignore ){

			letters[ small ] = Letter( small, booleanValue );
			letters[ captial ] = Letter( captial, booleanValue );
		}
	}
}

int readInteger( FILE *file, int start, int end){

	int input = 0;
	int result;

	while( printf("\nEnter an integer between %d - %d inclusive: ", start, end ) && !fflush(stdin) && ( ( result = scanf( " %d", &input ) ) != -1 && result != 1  ) || ( input < start || input > end ) ){

		cout<<endl<<"Illegal value. try again :";
	}

	if( -1 == result )
		return -1;

	return input;
}

void evaluateExpression( OperatorsMap& operators, LettersMap& letters ){

	fflush( stdin );
	cout<<"Expression: ";
	string expression = GetString( stdin );

	try{

		if( true == layman( expression, operators, letters ) )
			cout<<"The Expression evaluated to true."<<endl<<endl;
		else
			cout<<"The Expression evaluated to false."<<endl<<endl;

	}catch( char *e ){

		cout<<"Char* Exception: "<<e;
	}

}

void insertDefaultLetters( LettersMap& letters ){

	letters['t'] = Letter('t',true);
	letters['T'] = Letter('T',true);
	letters['f'] = Letter('f',false);
	letters['F'] = Letter('F',false);
}

void insertDefaultOperators( OperatorsMap& operators ){

	operators['>'] = Operator( 2, dragging );
	operators['~'] = Operator( 1, not );
}
/**
	Programmed By : Moaid Hathot
**/