/*
 * dynamic_array.hpp
 *
 *  Created on: Jan 13, 2017
 *      Author: nguyenvu
 */
#include <cstdlib>
#include <iostream>
#include <string.h>
#ifndef DYNAMIC_ARRAY_DYNAMIC_ARRAY_HPP_
#define DYNAMIC_ARRAY_DYNAMIC_ARRAY_HPP_
template<class el>
class dynamic_array{
public:
	dynamic_array();
	dynamic_array(const dynamic_array &a);//assignment operator
	~dynamic_array();
	el& operator [] (unsigned int index); //get array item
	void Add(const el &item); //Add item to the end of array

	unsigned int GetSize();//get size of array (elements)
	void SetSize(unsigned int newsize);//set size of array (elements)
	void Clear(); //clear array
	void Delete(unsigned int pos); //delete array item
	void* getptr(); //get void* pointer to array data

	enum exception { MEMFAIL }; //exception enum
private:
	el *array; //pointer for array's memory
	unsigned int size; //size of array (elements)
	unsigned int realsize; //actual size of allocated memory

	const static int dyn_array_step =128; //initial size of array memory (elements)
	const static int dyn_array_mult=2; //multiplier (enlarge array memory
};
template <class el>
dynamic_array<el>::dynamic_array(){
	realsize = dyn_array_step; //First, allocate step for dyn_array_step items
	size=0;
	array= (el *)malloc(realsize*sizeof(el));
	if(array == NULL)
		throw MEMFAIL;
}

template <class el>
dynamic_array<el>::~dynamic_array(){
	if(array){
		free(array); //Freeing memory
		array = NULL;
	}
}

template <class el>
dynamic_array<el>::dynamic_array(const dynamic_array &a){
	array = (el *)malloc(sizeof(el)*a.realsize);
	if (array == NULL)
		throw MEMFAIL;
	memcpy(array, a.array, sizeof(el)*a.realsize);
	//memcpy call -- coping memory contents
	realsize = a.realsize;
	size = a.size;
}

//template <class el>
//dynamic_array<el>& dynamic_array<el>::operator = (const dynamic_array &a) //Since majority of C++ doesn't support separation of template classes, you should save all source code to a single .h file
//{
//    if (this == &a) // in case somebody tries assign array to itself
//		return *this;
//
//	if (a.size == 0) // is other array is empty -- clear this array
//		Clear();
//
//	SetSize(a.size); // set size
//
//    memcpy(array, a.array, sizeof(el)*a.size);
//
//    return *this;
//}

template <class el>
unsigned int dynamic_array<el>::GetSize()
{
    return size; // simply return size
}


template <class el>
void dynamic_array<el>::SetSize(unsigned int newsize)
{
    size = newsize;

	if (size != 0)
	{
		// change array memory size
		// if new size is larger than current
		// or new size is less then half of the current
		if ((size > realsize) || (size < realsize/2))
		{
	    	realsize = size;
	    	array = (el *)realloc(array, sizeof(el)*size);

			if (array == NULL)
				throw MEMFAIL;
		}
	}
	else
		Clear();
}

template <class el>
void dynamic_array<el>::Delete(unsigned int pos)
{
	if (size == 1) // If array has only one element
		Clear(); // than we clear it, since it will be deleted
	else
	{
		// otherwise, shift array elements
		for(unsigned int i=pos; i<size-1; i++)
			array[i] = array[i+1];

		// decrease array size
		size--;
	}
}

template <class el>
void dynamic_array<el>::Clear() // clear array memory
{
    size = 0;
	array = (el *)realloc(array, sizeof(el)*dyn_array_step);
				  // set initial memory size again
	realsize = dyn_array_step;
}

template <class el>
void* dynamic_array<el>::getptr()
{
    return array; // return void* pointer
}

template <class el>
el& dynamic_array<el>::operator [] (unsigned int index)
{
    return array[index]; // return array element
}

template <class el>
void dynamic_array<el>::Add(const el &item)
{
    size++;

    if (size > realsize)
    {
		realsize *= dyn_array_mult;

		array = (el *)realloc(array, sizeof(el)*realsize);

		if (array == NULL)
			throw MEMFAIL;
    }

	array[size-1] = item;
}



#endif /* DYNAMIC_ARRAY_DYNAMIC_ARRAY_HPP_ */
