// zy-0501.cpp: 主项目文件。

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int i, k, m, n, num[50], *p;
	cout << "输入人数: ";
	cin >> n;
	p = num;
	for (i = 0;i<n;i++)
		*(p + i) = i + 1; // 以 1 至 n 为序给每个人编号
	i = 0; // i 为每次循环时计数变量
	k = 0; // k 为按 1,2,3 报数时的计数变量
	m = 0; // m 为退出人数
	while (m<n - 1) // 当退出人数比 n-1 少时(即未退出人数大于 1 时)执行循环体
	{
		if (*(p + i) != 0) k++;
		if (k == 3) // 将退出的人的编号置为 0
		{
			*(p + i) = 0;
			k = 0;
			m++;
		}
		i++;
		if (i == n) i = 0; // 报数到尾后，i 恢复为 0
	}
	while (*p == 0) p++;
	cout << "最后留下的人原来的编号是：" << *p << endl;
	system("pause");
	return 0;
}
