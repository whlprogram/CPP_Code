#include <bits/stdc++.h>
#define MAX 10000005
// A[i] 存放序列，dp[i] 存放以 A[i] 为结尾的连续序列的最大和
int A[MAX], dp[MAX];
// 求较大值
int min(int a, int b) {
    return a<b ? a : b;
}
int main() {
    int T, i, res;
    scanf("%d", &T);
    for(i=0; i<T; ++i) {        // 输入序列
        scanf("%d", &A[i]);
    }
    dp[0] = A[0];                // 边界
    for(i=1; i<T; ++i) {
        // 状态转移方程
        dp[i] = min(A[i], dp[i-1] + A[i]);
    }
    // 求最大连续子序列和
    res = dp[0];
    for(i=1; i<T; ++i) {
        if(dp[i] < res) {
            res = dp[i];
        }
    }
    printf("%d\n", res);        // 输出

    return 0;
}
