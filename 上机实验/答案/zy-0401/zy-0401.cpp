// zy-0401.cpp: 主项目文件。

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	char* line = new char;
	int i = 0,j;
	char ch=' ';
	
	cout << "请输入字符串："<<endl;
	cin.getline(line,1000);
	cout << "请输入删除字符：" << endl;
	cin >> ch;
	while (line[i] != '\0')
	{
		while (line[i] != ch)
		{
			i++;
		}
		int len = strlen(line);
		for (j = i;j<len - 1;j++)
		{
			line[j] = line[j + 1];
		}
		line[j] = '\0';
	}
	cout << line << endl;
	system("pause");
    return 0;
}
