// zy-0302.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
#define S(a,b,c) (a+b+c)/2
#define  AREA(a,b,c) sqrt(S(a, b, c)*(S(a, b, c) - a)*(S(a, b, c) - b)*(S(a, b, c) - c))
int main()
{
	float a, b, c;
	cout << "������a,b,c����:";
	cin >> a >> b >> c;
	if (a + b>c && a + c>b && b + c>a)
		cout << "���������=" << AREA(a, b, c) << endl;
	else
		cout << "��������ⲻ��һ��������!" << endl;
	system("pause");
	return 0;
}