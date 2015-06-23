/**
	Programmed By : Moaid Hathot
**/
#include "layman.h"
//#include "Arrays.h"
#include "Arrays.cpp"
#include "Utilities.h"
#include <math.h>

bool layman( std::string string, OperatorsMap& operators, LettersMap& letters ){

	unsigned int index;
	unsigned int counter  = 0;
	bool savedValue = false;
	bool evaluated = false;



	//for( index = 0; *( string + index ); ++index ){
	for( int index = 0; index < string.length(); ++index){

		//char current = *( string + index );
		char current = string[index];

		if( '(' == current )
			++counter;
		else if( ')' == current )
			--counter;
		//else if( ' ' == current )
			//; // do nothing
		//else if( _True != anOperator( operators, current ) )
		else if( NULL != operators[ current ].operatorAction() ){

			if( counter == 0 ){

				Operator op = operators[ current ];

				int leftLength = 0;
				int rightLength = 0;

				/*
				//if( (index - 2) > 0 )
				leftLength = Max(index - 2, 0);
				rightLength = Max( string.length() - (index + 3), 0 );

				char *leftString = (char*)malloc( leftLength + 1); // index + 1
				char *rightString = (char*)malloc( rightLength + 1); // index

				memcpy( leftString, string.c_str() + 1, leftLength ); // index, string.C_str()
				memcpy( rightString, string.c_str() + index + 2, rightLength); // string.c.str() + index + 1, string.length() - index
				*/
				

				/*
				leftLength = Max( 0, index );
				rightLength = Max( 0, string.length() - ( index + 1 ) ); // what if string.length() is 0 ?. though this might never happens because the only onary operator( ~ ) is left alliend.

				char *leftString = (char*)malloc( leftLength + 1 );
				char *rightString = (char*)malloc( rightLength + 1 );

				memcpy( leftString, string.c_str(), leftLength );
				memcpy( rightString, string.c_str() + index + 1, rightLength );
				*/

				// need the signed casting because a compiler bug with string.length(). 
				leftLength = Max( 0, signed(index - 2) );
				rightLength = Max( 0, (signed)(string.length() - ( index + 1 ) - 2) ); // what if string.length() is 0 ?. though this might never happens because the only onary operator( ~ ) is left alliend.
				// because the ( ) at the begining and the ending of the expression

				// + 1 for the null terminator
				char *leftString = (char*)malloc( leftLength + 1 );
				char *rightString = (char*)malloc( rightLength + 1 );

				memcpy( leftString, string.c_str() + 1, leftLength );
				memcpy( rightString, string.c_str() + index + 1 + 1, rightLength );
				

				*( leftString + leftLength ) = '\0'; // *( leftString + index ) = '\0'
				*( rightString + rightLength) = '\0'; // wasn't needed

				Array<bool> arr( op.argumentsCount() );

				if( op.argumentsCount() == 2 ){

					arr[0] = layman( leftString, operators, letters );
					arr[1] = layman( rightString, operators, letters );
				}
				else if( op.argumentsCount() == 1 )
					arr[0] = layman( rightString, operators, letters );

				bool result = operators[ current ].operatorAction()( arr );  // sent by reference => Array& arr

				free( leftString );
				free( rightString );

				return result;
			}
		}
		else if( 0 != letters[ current ].getLetter() ){

			if( evaluated )
				throw "Illegal Expression. Too many sequential letters";
			else
			evaluated = true;

			savedValue = letters[ current ].getValue();
		}
		else // unknown 
			throw "Illegal Expression. Unknown Letter/Operator";
			//return false;
			//return _Failure;

		if( 0 > counter )
			throw "Illegal Expression. Layman counter is negative";
			//return false;
	}

	if( false == evaluated || 0 != counter )
		throw "Illegal Expression.";

	return savedValue;
}
/**
	Programmed By : Moaid Hathot
**/