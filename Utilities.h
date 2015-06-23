#ifndef _Utilities_Header_0xCAFEBABE
#define _Utilities_Header_0xCAFEBABE

#include <iostream>
#include <map>
#include "Arrays.h"
//#include <stdio.h>

using std::cout;
using std::string;
using std::map;

#define WaitForResponse { cout<<"\n\nPress 'Enter' to continue..."; fflush( stdin ); getchar(); }
#define Max( a, b ) ( (a) >= (b) ? (a) : (b) )


//typedef enum { _Failure, _Sucess } _Result;

string GetString(FILE* inputSource );

#endif