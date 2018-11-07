#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define MAXN 50010
const int INF = 1e9;

int idx[MAXN];
int b[MAXN];
int a;
int dp[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        idx[a-1] = i;
    }
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        b[i] = idx[a-1];
        dp[i] = INF; // 初始化为无限大
    }

    //最长递增子序列
    int pos = 0;  // 记录dp当前最后一位的下标
    dp[0] = b[0]; // dp[0]值显然为a[0]
    for (int i = 1; i < n; i++) {
        if (b[i] > dp[pos]) // 若a[i]大于dp数组最大值，则直接添加
            dp[++pos] = b[i];
        else // 否则找到dp中第一个大于等于a[i]的位置，用a[i]替换之。
            dp[lower_bound(dp, dp + pos + 1, b[i]) - dp] = b[i]; // 二分查找
    }

    printf("%d\n", pos+1);
    return 0;
}
