/**
	Programmed By : Moaid Hathot
**/
#include "Arrays.h"

template<class E>
Array<E>::Array( arrays_length _size = 0, E *toCopy = NULL ){
	
	initResources( _size, toCopy );
}

template<class E>
Array<E>::Array( const Array& toCopy ):size(toCopy.size){
	
	this( toCopy.size, toCopy.elements );
}

template<class E>
Array<E>::~Array(){

	freeResources();
}

template<class E>
Array<E>& Array<E>::operator=( const Array& toCopy ){

	freeResources();

	initResources( toCopy.size, toCopy.elements );
}

template<class E>
E& Array<E>::operator[]( const int index ){

	if( 0 > index || index >= size )
		throw "index out of bound exception";
		//throw "index(" + index +") is out of bound. array size = (" + size + ")";

	return elements[ index ];
}

template<class E>
void Array<E>::copyArray( arrays_length length, E *arr ){
	
	for( unsigned int index = 0; index < length; ++index )
		elements[ index ] = arr[ index ];
}

template<class E>
void Array<E>::allocateArray(){

	if( 0 == size )
		return;

	elements = new E[ size ];
}

template<class E>
void Array<E>::deallocateArray(){

	if( NULL == elements )
		return;

	delete[] elements;

	elements = NULL;
}

template<class E>
void Array<E>::freeResources(){

	deallocateArray();

	size = 0;
}

template<class E>
void Array<E>::initResources( arrays_length size, E *toCopy ){

	this->size = size;

	if( 0 == size || NULL == toCopy )
		this->elements = NULL;

	allocateArray();
	
	if( NULL != toCopy )
		copyArray( size, toCopy );
}
/**
	Programmed By : Moaid Hathot
	Braude College
**/