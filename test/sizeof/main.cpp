#include <iostream>

using namespace std;

int main()
{
	cout << sizeof(8) << endl; //自动转化为int类型
        cout << sizeof(8.8) << endl; //自动转化为double类型，注意，不是float类型
        cout << sizeof("ab") << endl;
	cout << "Size of char is: " << sizeof(char) << endl;
	cout << "Size of unsigned char is: " << sizeof(unsigned char) << endl;
	cout << "Size of signed char is: " << sizeof(signed char) << endl;
	cout << "Size of int is: " << sizeof(int) << endl;
	cout << "Size of short is: " << sizeof(short) << endl;
	cout << "Size of long is: " << sizeof(long) << endl;
	cout << "Size of long int is: " << sizeof(long int) << endl;
	cout << "Size of signed int is: " << sizeof(signed int) << endl;
	cout << "Size of unsigned int is: " << sizeof(unsigned int) << endl;
	cout << "Size of unsigned long int is: " << sizeof(unsigned long int) << endl;
	cout << "Size of long long int is: " << sizeof(long long int) << endl;
	cout << "Size of unsigned long long is: " << sizeof(unsigned long long) << endl;
	cout << "Size of float is: " << sizeof(float) << endl;
	cout << "Size of double is: " << sizeof(double) << endl;
	cout << "Size of long double is: " << sizeof(long double) << endl;
	cout << "Size of (long *) is:" << sizeof(long *) << endl;
	cout << "Size of (void *) is:" << sizeof(void *) << endl;
	cout << "Size of (char *) is:" << sizeof(char *) << endl;

	char *p;
	cout << "Size of p is:" << sizeof(p) << endl;

	return 0;
}
