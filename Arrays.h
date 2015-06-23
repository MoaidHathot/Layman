//#pragma once

#ifndef _Arrays_Header_0xCAFEBABE
#define _Arrays_Header_0xCAFEBABE

//#include <stdio.h>


typedef size_t arrays_length;

template<class E>
class Array{

	E *elements;
	arrays_length size;

	void allocateArray();
	void deallocateArray();
	void copyArray( arrays_length length, E *arr );
	void initResources( arrays_length size, E *toCopy );
	void freeResources();

public:

	Array( arrays_length size = 0, E *toCopy = NULL );
	Array( const Array& toCopy );
	~Array();

	arrays_length length() const{ return size; }

	Array& operator = ( const Array& toCopy );
	E& operator [] ( const int index );
};

#endif