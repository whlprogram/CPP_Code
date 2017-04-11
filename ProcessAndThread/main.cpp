#include <iostream>

using namespace std;
//进程和线程
//整个项目就是个进程，getmax(), main() 就是一个个小的线程
//一个函数(线程)有语法错误，项目就不能执行
int getmax(int x, int y);   // 定义getmax函数

int main()
{
	int  a, b, Max;
	cin >> a >> b;
	Max = getmax(a, b);
	cout<<"Max=" << Max <<endl;
	return 0;
}
int getmax(int x, int y)
{
	int z = x>y?x:y;
	return z;
}
