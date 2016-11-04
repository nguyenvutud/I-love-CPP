/*
 * testsocket_test.cpp
 *
 *  Created on: Oct 7, 2016
 *      Author: nguyenvu
 */

#include "testsocket.h"
#include <iostream>
using namespace socketprogramming;
using namespace std;
int ffmain()
{
	socketprogramming::testsocket ts;
	cout<<ts.getaddressinformation() << endl;
	return 0;
}
