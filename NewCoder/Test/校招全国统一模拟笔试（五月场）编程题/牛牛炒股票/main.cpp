/*
‘≠Ã‚¡¥Ω” https://www.nowcoder.com/question/next?pid=10714908&qid=164575&tid=16850519
*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int* X = new int[N+1]();
    int* Y = new int[N+1]();
    int* dp = new int[M+1]();
    for(int i=1; i<=N; i++){
        cin >> X[i] >> Y[i];
        Y[i] -= X[i];
    }
    for(int i=1; i<=N; i++)
        for(int j=X[i]; j<=M; j++)
            dp[j] = max(dp[j], dp[j-X[i]]+Y[i]);
    cout << dp[M] << endl;
    delete X,Y,dp;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int dp[1005];
int c[1005][2];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
        dp[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &c[i][0], &c[i][1]);
        for(int j = c[i][0]; j <= m; j++)
            dp[j] = max(dp[j], dp[j-c[i][0]] + c[i][1]);
    }
    printf("%d\n", dp[m] - m);
    return 0;
}
