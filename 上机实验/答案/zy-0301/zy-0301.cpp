// zy-0301.cpp: 主项目文件。

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	void godbaha(int);
	int n;
	cout << "请输入一个大于（等于）6的偶数:";
	cin >> n;
	godbaha(n);
	system("pause");
	return 0;
}
void godbaha(int n)
{
	int prime(int);
	int a, b;
	for (a = 3;a <= n / 2;a++)
	{
		if (prime(a))
		{
			b = n - a;
			if (prime(b))
				cout << n << "=" << a << "+" << b << endl;
		}
	}
}
int prime(int m)
{
	int i, k = sqrt(m);
	for (i = 2;i <= k;i++)
		if (m%i == 0) break;
	if (i>k) return 1;
	else return 0;
}