//============================================================================
// Name        : Test_CPP.cpp
// Author      : Vu Nguyen
// Version     :
// Copyright   : TU Dresden
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
//using namespace libsNV;
using namespace std;
namespace libsHP
{
void inthongtin(struct Books *book);
struct Books
{
	char tieude[30];
	char tacgia[30];
};
template <class T>
T Max(T a, T b)
{
	return (a>b ? a: b);
}
template <class T>
T Max(T a, T b, T c)
{
	if(a>b)
		if(b>c) return a;
		else
			return c;
	else
		if(b>c) return b;
		else return c;
}
template <class T, int n>
void PrintZero(T x[n])
{
	for(int i=0;i<n;i++)
		if(x[i] ==0)
			cout << i;
}
void mainff() {
//	USING THE AUTO KEYWORK IN C++ V3

//	auto int x;
//	int y=x; //Loi vi bien x chua duoc khoi tao

	//Chuyen thanh code sau trinh bien dich se chap nhan
//	auto int x=0; //tuong duong voi khai bao int x=0, vi bien nay duoc luot bo
//	int b=x;
//  Biến auto sẽ được khởi tạo và tồn tại trong 1 phạm vi cục bộ cho đến khi thoát khỏi phạm vi cục bộ sẽ được thu hồi

//  SU DUNG TU KHOA AUTO TRONG C++11

//	Với từ khóa auto ở phiên bản C++11 nó có ý nghĩa khác hoàn toàn với C++03, nó có nghĩa là, tự động nhận dạng kiểu dữ liệu thông qua kiểu dữ liệu của giá trị khởi tạo ra nó
// STDIO_li_i kiểu list<int>::iterator do li.begin() trả về kiểu list<int>::iterator
// STDIO_c kiểu char do 'c' kiểu char
//	auto STDIO_c = 'c';
//
//	// STDIO_i kiểu int do 10 kiểu int
//	auto STDIO_i = 10;
//
//	// STDIO_p kiểu int* do new int[3] trả về kiểu int*
//	auto STDIO_p = new int[3];

//	list<int> li;
//	auto STDIO_li_i = li.begin();

//	TEST KIEU DU LIEU CON TRO
//	Kieu con tro trong cpp khong cho gan truc tiep nhu int *tp = p;
//	int *tp;
//	*tp=5;
//	cout <<*tp <<"\n";

	struct Books quyen1;
	strcpy(quyen1.tieude,"LTNN Lap trinh");
	strcpy(quyen1.tacgia,"Nguyen Van A");
	inthongtin(&quyen1);

	//Goi Template
	int x1=500,y1=100;
	cout<<"Max 2 so nguyen:"<<Max<int>(x1,y1)<<endl;

	float x2=43.545, y2=98.43,z=3434;
	cout<<"Max 2 so thuc:"<<Max<float>(x2,y2)<<endl;
	cout<<"Max 3 so thuc:"<<Max<float>(x2,y2,z)<<endl;


	int a[5] = {5,3,0,4,0};

	PrintZero<int, 5>(a);

	//Test Class

	std::cout << "!!!Press enter to finish!!!" << endl; // prints !!!Hello World!!!

}
void inthongtin(struct Books *book)
{
	cout << "Tieu de:" << book->tieude <<endl;
	cout << "tac gia:" << book->tacgia <<endl;
};

}
