// zy-01.cpp: 主项目文件。

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	cout << "请输入加密字符串：";
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
