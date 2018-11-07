/*
整数划分
https://blog.csdn.net/u013174702/article/details/45620723

将整数n分成k份，且每份不能为空，任意两种划分方案不能相同(不考虑顺序)。
例如：n=7，k=3，下面三种划分方案被认为是相同的。
1 1 5
1 5 1
5 1 1
问有多少种不同的分法。
*/

#include<stdio.h>
using namespace std;

int f[205][10];
int main()
{
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
		f[i][1] = 1;

	f[0][0] = 1;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= k && j <= i; j++){
			f[i][j] = f[i - 1][j - 1] + f[i - j][j];
		}
	}
	printf("%d\n", f[n][k]);
	return 0;
}


/*
#include<iostream>

using namespace std;

void SORT(int temp[], int fff, int lll)
{
	if (fff >= lll) {
		return;
	}
	int first = fff;
	int last = lll;
	int key = temp[first];
	while (first < last)
	{
		while (first<last && temp[last]>=key)
		{
			--last;
		}
		temp[first] = temp[last];
		while (first < last && temp[first] <=key)
		{
			++first;
		}
		temp[last] = temp[first];
	}

	temp[first] = key;
	SORT(temp, fff, first - 1);
	SORT(temp, first + 1, lll);
}

int main() {

	int temp[] = {4,3,2,7,6,9,8};
	SORT(temp, 0, sizeof(temp)/sizeof(int)-1);
	for (int i = 0; i < sizeof(temp)/sizeof(int); i++) {
		cout << temp[i] << " ";
	}

	//system("pause");
	return 0;
}
*/
