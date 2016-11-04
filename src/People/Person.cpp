/*
 * Person.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: nguyenvu
 */

#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

namespace libsNV {

int Person::stt=0;

Person::Person() {
	// TODO Auto-generated constructor stub
	this->name="Anonymous";
	stt= stt+1;

}
Person::Person(string name)
{
	this->name=name;
	stt=stt+1;
}

Person::~Person() {
	// TODO Auto-generated destructor stub
	cout << "Destructor called" <<endl;

}
string Person::getName(){
	return name;
}
void Person::setName(string n){
	name=n;

}
void Person::Print(){
	cout << "The number of people:" << stt << endl;
}
} /* namespace libsNV */

