#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	/*
	struct Student{//
		int num;        //4
		char name[20];  //20
		char sex;       //1
		int age;        //4
		float score;    //4
		char addr[30];  //30
	};
	Student stu1,stu2;
	cout << "int " << sizeof(int) << endl;          //int 4
	cout << "char " << sizeof(char) << endl;        //char 1
	cout << "float " << sizeof(float) << endl;      //float 4
	cout << "name " << sizeof(stu2.name) << endl;   //name 20
	cout << "addr " << sizeof(stu2.addr) << endl;   //addr 30
	cout << sizeof(Student) << endl;                //68 == 4+20+4+4+4+32
	cout << sizeof(stu1) << endl;                   //68
	cout << sizeof(stu2) << endl;                   //68
	printf("%d\n", sizeof(Student));                //68
	printf("%d\n", sizeof(stu1));                   //68
	printf("%d\n", sizeof(stu2));                   //68
	*/
	cout << "-6%10==" << (-6)%10 << endl;
	return 0;
}
