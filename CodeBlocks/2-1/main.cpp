// 2-1.cpp: ����Ŀ�ļ���
#include "stdafx.h"
#include <iostream>
#include <climits>              // use limits.h for older systems
int main()
{
	using namespace std;
	int n_int = INT_MAX;        // initialize n_int to max int value
	short n_short = SHRT_MAX;   // symbols defined in climits file
	unsigned short shot = n_short;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	// sizeof operator yields size of type or of variable
	cout << "int is " << sizeof (int) << " bytes." << endl;
	cout << "short is " << sizeof n_short << " bytes." << endl;
	cout << "unsigned short is " << sizeof shot << " bytes." << endl;
	cout << "long is " << sizeof n_long << " bytes." << endl;
	cout << "long long is " << sizeof n_llong << " bytes." << endl;
	cout << endl;

	cout << "Maximum values:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "unsigned short: " << shot << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl << endl;

	cout << "Minimum int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;

	n_short=n_short+1;
	shot=shot+1;
	cout << "short+1: " << n_short << endl;
	cout << "unsigned short+1: " << shot << endl;
	system("pause");
	return 0;
}
