// zy-0202.cpp: 主项目文件。

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	char i, j, k; /* i 是 a 的对手;j 是 b 的对手;k
				  是 c 的对手*/
	for (i = 'X';i <= 'Z';i++)
		for (j = 'X';j <= 'Z';j++)
			if (i != j)
				for (k = 'X';k <= 'Z';k++)
					if (i != k && j != k)
						if (i != 'X' && k != 'X' && k != 'Z')
							cout << "A vs " << i << endl << "B vs " << j << endl << "C vs " << k << endl;
	system("pause");
	return 0;
}