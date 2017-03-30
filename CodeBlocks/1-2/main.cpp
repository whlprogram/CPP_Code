// 1-2.cpp: 主项目文件。

#include  <iostream>
using namespace std;

int  getmax(int x, int y);   // 定义max函数

int  main(  )
{
	//int getmax(int x,int y);
	int  a, b, m ;				// 变量声明
	cin >> a>>b ;			// 输入变量 a、b的值
	m = getmax(a, b) ;		// 调用函数max，将得到的值赋给m
	cout<<"max=" << m << '\n' ;		//   输出m
	return 0;

}
int  getmax(int x, int y)   // 定义max函数
{
	int z;               // 变量声明
	if (x>y) z = x;
	else  z = y;
	return (z);
}
