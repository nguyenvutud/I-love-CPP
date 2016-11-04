#include <iostream>
#include <string.h> //when I add .h into string, the the programs run well?
#include <pthread.h>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

void teststringtype()
{
	char str1[15]="Hello";
	char str2[15]="Chrismas";
	char str3[15];
	strcpy(str3,str1);
	cout <<str3 <<endl;
	strcat(str1,str2);
	cout<<str1<<endl;
	cout<<strlen(str1)<<endl;
	cout<<str1<<endl;
}
void testpointer(){
	int *p,*q,n=10;
	int x[] ={1,5,7,-2,3};
	p=x;
	for(int i=0;i<=(int) sizeof(*p);++i)
		cout<<p[i];
	cout<<endl;
	q=&n;
	(*q)++;
	cout<<*q<<endl;
	cout<<n<<endl;
}
void testvector()
{
	int n=100;
	vector<int> A;
	for(int i=0;i<n;i++)
		A.push_back(i*2);

	for(int i=0;i<A.size();i++)
		cout<<A[i] <<" ";

}
void testrandom()
{
	//khai bao thu vien cdtdlib
	srand(time(NULL));
	int a=rand();
	cout<<"\nThe number has just random is:"<<a <<endl;
	cout<<RAND_MAX<<endl;

}
