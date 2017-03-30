// zy-0302.cpp: 主项目文件。

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
#define S(a,b,c) (a+b+c)/2
#define  AREA(a,b,c) sqrt(S(a, b, c)*(S(a, b, c) - a)*(S(a, b, c) - b)*(S(a, b, c) - c))
int main()
{
	float a, b, c;
	cout << "请输入a,b,c三边:";
	cin >> a >> b >> c;
	if (a + b>c && a + c>b && b + c>a)
		cout << "三角形面积=" << AREA(a, b, c) << endl;
	else
		cout << "输入错误，这不是一个三角形!" << endl;
	system("pause");
	return 0;
}