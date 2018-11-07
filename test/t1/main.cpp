/*#include <iostream>

using namespace std;

int main()
{
    int b = 2;
    const int* a1 = &b;
    //const* int a2 = &b;
    const int* const a3 = &b;
    int const* const a4 = &b;
    cout << a1 << endl;
    cout << a3 << endl;
    cout << a4 << endl;
    return 0;
}*/
#include <iostream>
using namespace std;
int main(){
	struct Student{//
		int num;
		char name[20];
		char sex;
		int age;
		float score;
		char addr[30];
	};
	Student stu1,stu2;
	cout << "int " << sizeof(int) << endl;//4
	cout << "char " << sizeof(char) << endl;//1
	cout << "float " << sizeof(float) << endl;//4
	cout << "stu1-int " << sizeof(stu1.num) << endl;//4
	cout << "stu1-char " << sizeof(stu1.sex) << endl;//1
	cout << "stu1-float " << sizeof(stu1.score) << endl;//4
	cout << "char[] " << sizeof(stu1.name) << endl;//20
	cout << "char[] " << sizeof(stu1.addr) << endl;//30
	cout << sizeof(Student) << endl; //68
	cout << sizeof(stu1) << endl;    //68
	cout << sizeof(stu2) << endl;    //68
	return 0;
}
