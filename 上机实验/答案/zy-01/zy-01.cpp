// zy-01.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	cout << "����������ַ�����";
	char* c=new char;
	char* c2=new char;
	cin >> c;
	for (int i = 0;c[i]!='\0';i++)
	{
		c2[i] = c[i] + 4;
	}
	cout << c2 << endl;
	system("pause");
    return 0;
}
