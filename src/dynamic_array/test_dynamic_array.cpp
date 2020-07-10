///*
// * test_dynamic_array.cpp
// *
// *  Created on: Jan 13, 2017
// *      Author: nguyenvu
// */
//#include <iostream>
//
//#include "dynamic_array.h"
//using namespace std;
//
////function for outputting array items
//void output_array(dynamic_array<int> &array)
//{
//	for(unsigned int i = 0; i< array.GetSize(); i++)
//		cout << array[i] << ", ";
//	cout << endl;
//}
////In majority of real-life applications you sould use STL vector class for dynamic arrays, since it provides more detailed and reliabile implementation
////As you may see in operator [] source code, Dynamic_array arrays doesn't have boundary checking.
////Dynamic_array class is not suitable for storing custom C++ objects(with constructors), becase of low-level memory access functions (malloc, memcpy, realloc). It can handle only basic types (char, int, double, float) and structs based on basic types.
//int run(void)
//{
//	dynamic_array<int> array;
//	//setting array size
//	array.SetSize(15);
//	//filling array with pseudo-random values
//	for(unsigned int i=0; i<15; i++)
//		array[i] = rand() % 100;
//	//let add some values using Add()
//	array.Add(7);
//	array.Add(34);
//	array.Add(-10);
//	//output all array items
//
//	output_array(array);
//	// delete 1-st  and last items
//		array.Delete(0);
//		array.Delete(array.GetSize() - 1);
//
//		// output all array items (again)
//		output_array(array);
//
//		// let's sort all array items using extemly ineffective sort
//		for(unsigned int i=0; i<array.GetSize();)
//			if (array[i] > array[i+1])
//			{
//				int x = array[i];
//				array[i] = array[i+1];
//				array[i+1] = x;
//				i = 0;
//				continue;
//			}
//			else
//				i++;
//
//		output_array(array);
//
//		// create another array, based on first
//		dynamic_array<int> array2(array);
//		array2.Clear(); // clear it
//
//		// check multiple addition
//		for(int i=0; i<1000000; i++)
//			array2.Add(rand());
//
//		// check assigment operator
//		array = array2;
//
//		// output array
//		cout << "array 2 size " << array2.GetSize() << endl;
//		cout << "array 1 size " << array.GetSize() << endl;
//
//		// check random element
//		int testel = rand() % 1000000;
//		cout << "array 2 element " << testel << " = " << array2[testel] << endl;
//		cout << "array 1 element " << testel << " = " << array[testel] << endl;
//
//		// that's all!
//		return 0;
//}
//
//
//
