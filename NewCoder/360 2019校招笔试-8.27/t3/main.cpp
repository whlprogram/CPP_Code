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
        dp[i] = INF; // ��ʼ��Ϊ���޴�
    }

    //�����������
    int pos = 0;  // ��¼dp��ǰ���һλ���±�
    dp[0] = b[0]; // dp[0]ֵ��ȻΪa[0]
    for (int i = 1; i < n; i++) {
        if (b[i] > dp[pos]) // ��a[i]����dp�������ֵ����ֱ�����
            dp[++pos] = b[i];
        else // �����ҵ�dp�е�һ�����ڵ���a[i]��λ�ã���a[i]�滻֮��
            dp[lower_bound(dp, dp + pos + 1, b[i]) - dp] = b[i]; // ���ֲ���
    }

    printf("%d\n", pos+1);
    return 0;
}
