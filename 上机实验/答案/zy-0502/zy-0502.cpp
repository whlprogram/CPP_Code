// zy-0502.cpp: 主项目文件。

#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	char str[50], *pstr;
	int i, j, k, m, e10, digit, ndigit, a[10], *pa;
	cout << "input a string:" << endl;
	cin.getline(str,50);
	cout << endl;
	pstr = &str[0]; //字符指针 pstr 指向数组 str 首元素
	pa = &a[0]; //指针 pa 指向 a 数组首元素
	ndigit = 0; //ndigit 代表有多少个整数
	i = 0; //i 代表字符串中的第几个字符/
	j = 0; //j 代表连续数字的位数
	while (*(pstr + i) != '\0')
	{
		if ((*(pstr + i) >= '0') && (*(pstr + i) <= '9'))
			j++;
		else
		{
			if (j > 0)
			{
				digit = *(pstr + i - 1) - 48; //将个数位赋予 digit
				k = 1;
				while (k < j) //将含有两位以上数的其它位的数值累计于 digit
				{
					e10 = 1;
					for (m = 1;m <= k;m++)
						e10 = e10 * 10; //e10 代表该位数所应乘的因子
					digit = digit + (*(pstr + i - 1 - k) - 48)*e10; //将该位数的数值累加于 digit
					k++; //位数 k 自增
				}
				*pa = digit; //将数值放在数组a中
				ndigit++;
				pa++; //指针 pa 指向 a 数组下一元素
				j = 0;
			}
		}
		i++;
	}
	if (j > 0) //以数字结尾字符串的最后一个数据
	{
		digit = *(pstr + i - 1) - 48; //将个数位赋予 digit
		k = 1;
		while (k < j) // 将含有两位以上数的其它位的数值累加于 digit
		{
			e10 = 1;
			for (m = 1;m <= k;m++)
				e10 = e10 * 10; //e10 代表位数所应乘的因子
			digit = digit + (*(pstr + i - 1 - k) - 48)*e10; //将该位数的数值累加于 digit
			k++; /*位数 K 自增*/
		}
		*pa = digit; //将数值放到数组 a 中
		ndigit++;
		j = 0;
	}
	//printf("There are %d numbers in this line. They	are:\n", ndigit);
	j = 0;
	pa = &a[0];
	for (j = 0;j < ndigit;j++) //打印数据
		cout << *(pa + j) << endl;
	cout << endl;
	system("pause");
	return 0;
}