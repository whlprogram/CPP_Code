// zy-0501.cpp: ����Ŀ�ļ���

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int i, k, m, n, num[50], *p;
	cout << "��������: ";
	cin >> n;
	p = num;
	for (i = 0;i<n;i++)
		*(p + i) = i + 1; // �� 1 �� n Ϊ���ÿ���˱��
	i = 0; // i Ϊÿ��ѭ��ʱ��������
	k = 0; // k Ϊ�� 1,2,3 ����ʱ�ļ�������
	m = 0; // m Ϊ�˳�����
	while (m<n - 1) // ���˳������� n-1 ��ʱ(��δ�˳��������� 1 ʱ)ִ��ѭ����
	{
		if (*(p + i) != 0) k++;
		if (k == 3) // ���˳����˵ı����Ϊ 0
		{
			*(p + i) = 0;
			k = 0;
			m++;
		}
		i++;
		if (i == n) i = 0; // ������β��i �ָ�Ϊ 0
	}
	while (*p == 0) p++;
	cout << "������µ���ԭ���ı���ǣ�" << *p << endl;
	system("pause");
	return 0;
}
