/*
 * Hinhchunhat.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: nguyenvu
 */
#include "Hinhchunhat.hpp"

#include <iostream>
using namespace std;
namespace libsNV
{
	Hinhchunhat::Hinhchunhat()
	{
		chieudai=0;chieurong=0;
	};
	Hinhchunhat::Hinhchunhat(int a, int b){
		chieudai=a;chieurong=b;
	}
	int Hinhchunhat::getChieudai(){
			return chieudai;
		}
	int Hinhchunhat::getChieurong(){
			return chieurong;
		}
	int Hinhchunhat::Dientich()
		{
			return chieudai*chieurong;
		}
	int Hinhchunhat::Chuvi()
		{
			return 2*(chieudai+chieurong);
		}

}
//using namespace libsNV;
//int ffmain()
//{
//	Hinhchunhat hcn(5, 100);
//	cout <<hcn.Dientich() <<endl;
//	Person sv("Nguyen Van B");
//	cout << "Sinh vien co ten:"<< sv.getName() <<endl;
//	return 0;
//
//}


