// zy-0401.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	char* line = new char;
	int i = 0,j;
	char ch=' ';
	
	cout << "�������ַ�����"<<endl;
	cin.getline(line,1000);
	cout << "������ɾ���ַ���" << endl;
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
