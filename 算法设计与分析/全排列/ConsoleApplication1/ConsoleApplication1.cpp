// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
template<class Type>
void Perm(Type list[], int k, int m)
{
	if (k == m)
	{
		for (int i = 0; i <= m; i++)
			cout << list[i];
		cout << endl;
	}
	else
	{
		for (int i = k; i <= m; i++)
		{
			Swap(list[k],list[i]);
			Perm(list,k+1,m);
			Swap(list[k], list[i]);
		}
	}
}
template<class Type>
inline void Swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}

int main()
{

	int list[] = {1,2,3,4};
	Perm(list,0,3);

	return 0;
}

