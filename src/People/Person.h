/*
 * Person.h
 *
 *  Created on: Oct 1, 2016
 *      Author: nguyenvu
 */

#ifndef PEOPLE_PERSON_H_
#define PEOPLE_PERSON_H_
#include <string>
using namespace std;

namespace libsNV {

class Person {
private: string name;
private: static int stt;

public:
	Person();
	Person(string);
	virtual ~Person();
public:
	string getName();
	void setName(string);
	void Print();
};

} /* namespace libsNV */

#endif /* PEOPLE_PERSON_H_ */
