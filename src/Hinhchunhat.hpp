/*
 * Hinhchunhat.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: nguyenvu
 */
#include <iostream>
using namespace std;
namespace libsNV
{
	class Hinhchunhat{
	private:
		int chieudai,chieurong;
	public:
		Hinhchunhat();
		Hinhchunhat(int,int);
		int getChieudai();
		int getChieurong();
		int Dientich();
		int Chuvi();

	};
}
