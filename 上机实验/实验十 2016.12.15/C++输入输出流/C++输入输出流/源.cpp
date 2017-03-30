#include<iostream>
#include<iomanip>
using namespace std;
void main()
{
	int a1;   char a2;    double a3;
	cin >> a1;
	cin >> a2;
	cin >> a3;
	//(1)
	cout << a1 << "     " << a2 << "     " << a3 << endl;
	//(2)
	cout.setf(ios::left);
	cout.setf(ios::showpos);
	cout.setf(ios::internal);
	cout <<setw(10)<<a1<<endl;
	cout.unsetf(ios::internal);
	cout.unsetf(ios::showpos);
	cout.unsetf(ios::left);
	//(3)
	cout.setf(ios::right);
	cout.setf(ios::fixed);
	cout << setfill('*') << setw(15) << a2 << endl;
	cout.unsetf(ios::fixed);
	cout.unsetf(ios::right);
	//(4)
	cout.setf(ios::left);
	cout.precision(3);
	cout << setw(15) << a3 << endl;
}