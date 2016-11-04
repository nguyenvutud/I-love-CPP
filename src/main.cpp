#include <iostream>
#include "People/Person.h" //Thay doi cap dau <> thanh "" chuong trinh chay binh thuong
#include "Hinhchunhat.hpp"
#include <string.h> //when I add .h into string, the the programs run well?
#include <pthread.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <assert.h>
#include "testsomemethods.hpp"
#include <fstream> //write and read file
#define NUMBERTHREAD 4
using namespace libsNV;

using namespace std;

///This is my second commit
///this will be shown after I commit!
//void *subthread(void *threadid)
//{
//	cout<<"Hello World, From thread ID:"<< threadid << endl;
//	pthread_exit(NULL);
//}
void *InLoiChao(void *threadid)
{

   cout << "Hello World! Thread ID la " << threadid << endl;
   pthread_exit(NULL);
}
void testthread(){
//	pthread_t threads[NUMBERTHREAD];
//	int rc,i;
//	for(i=0;i<NUMBERTHREAD;i++)
//	{
//		cout <<"\nmain() dang tao thread:"<<i <<endl;
//		rc=pthread_create(&threads[i],NULL,subthread,(int *)i);
//		if(rc){
//			cout<<"Can not create thead"<<rc<<endl;
//			exit(-1);
//		}
//	}
//	pthread_exit(NULL);
//	 pthread_t threads[NUMBERTHREAD];
//	   int rc;
//	   int i;ing
//	   for( i=0; i < NUMBERTHREAD; i++ ){
//	      cout << "\nmain() : dang tao thread! " << i << endl;
//	      rc = pthread_create(&threads[i], NULL,
//	                          InLoiChao, (int *)i);
//	      if (rc){
//	         cout << "\nError: Khong the tao thread!" << rc << endl;
//	         exit(-1);
//	      }
//	   }
//	   pthread_exit(NULL);
}
void print_number(int* myInt) {
  assert (myInt!=NULL && "Loi");
  printf ("%d\n",*myInt);
}
void testexceptiont(){
	int a=10;
		  int * b = NULL;
		  int * c = NULL;

		  b=&a;

		  print_number(b);
		  print_number(c);
}
//Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.
//
//The content of the newly allocated block of memory is not initialized, remaining with indeterminate (khong ro, map mo, vo han) values.
//
//If size is zero, the return value depends on the particular library implementation (it may or may not be a null pointer), but the returned pointer shall not be dereferenced.
void test_malloc_function(){
	 int i,n;
	 char * buffer;

	 printf ("How long do you want the string? ");
	 scanf ("%d", &i);

	 buffer = (char*) malloc (i+1);
	 if (buffer==NULL) exit (1);

	 for (n=0; n<i; n++)
	   buffer[n]=rand()%26+'a';
	 buffer[i]='\0';

	 printf ("Random string: %s\n",buffer);
	 free (buffer);

	 //another example
	  char *str;

	  /* Initial memory allocation */
	  str = (char *) malloc(15);
	  strcpy(str, "tutorialspoint");
	  printf("String = %s,  Address = %u\n", str, str);

	  /* Reallocating memory */
	  str = (char *) realloc(str, 25);
	  strcat(str, ".com");
	  printf("String = %s,  Address = %u\n", str, str);

	  free(str);

}
//Test tu khoa VIRTUAL
class coso
{
    public:
      virtual void show()
      {
                cout<<"\n  Hien thi lop co so:";
      }
      void display()
      {
              cout<<"\n  Trung bay lop co so:" ;
      }
};

class kethua:public coso
{
   public:
      void display()
      {
              cout<<"\n  Trung bay lop ke thua:";
      }
      void show()
      {
              cout<<"\n  Hien thi lop ke thua:";
      }
};
void test_virtual(){
	coso obj1;
	   coso *p;
	   cout<<"\n\t P tro toi lop co so:\n"  ;

	   p=&obj1;
	   p->display();
	   p->show();

	   cout<<"\n\n\t P tro toi lop ke thua:\n";
	   kethua obj2;
	   p=&obj2;
	   p->display();
	   p->show();
}
void writeCSVfile()
{
	ofstream myfile;
	myfile.open("data.csv");
	myfile<< "This is the content of the file \n";
	myfile<<"a,b,c,\n";
	myfile<<"1,2,3.1415,\n";
	myfile<<"nguyen;vu,\n";
	myfile.close();
	cout<<"finishing writing file! \n";


}
void readfile(){
		// 2. Mở file
		fstream f;
		f.open("Input.txt", ios::in);

		// 3. Đọc dữ liệu từ file vào string data
		string data;

		// *** Đọc từng dòng và nối vào data
		string line;
		while (!f.eof())
		{
			getline(f, line);
			data += line;
		}

		// 4. Đóng file
		f.close();

		// Thể hiện data ra màn hình
		cout << data;
}
void test_random_function()
{
	srand (time(NULL));
	for(int i=1;i<=10;i++)
	{
//		double t=rand();
		double t= (double) rand()/(RAND_MAX);
		if(t<=0.1)
			cout<<t << "   ";
	}

}
int main(){

//	libsNV::Person nv("Hoang Thi P");
//	cout<< nv.getName() << endl;
//	nv.Print();
//
//	libsNV::Hinhchunhat hcn(7,4);
//	cout<<"Dien tich hinh chu nhat la:"<<hcn.Dientich() <<endl;
//	cout<<"Chu vi hinh chu nhat la :"<<hcn.Chuvi() <<endl;
//	teststringtype();
//	testpointer();
//	//testthread();
//	testvector();
//	testrandom();
//	cout<<"PI="<<PI <<endl;
//	test_malloc_function();
//
//	testexceptiont();
//	writeCSVfile();
//	readfile();
//	test_virtual();
	test_random_function();
	cout<<"Press enter to exit!";
	return 0;
}
