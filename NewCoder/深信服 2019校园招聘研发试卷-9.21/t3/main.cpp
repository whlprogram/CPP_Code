#include <bits/stdc++.h>
#define MAX 10000005
// A[i] ������У�dp[i] ����� A[i] Ϊ��β���������е�����
int A[MAX], dp[MAX];
// ��ϴ�ֵ
int min(int a, int b) {
    return a<b ? a : b;
}
int main() {
    int T, i, res;
    scanf("%d", &T);
    for(i=0; i<T; ++i) {        // ��������
        scanf("%d", &A[i]);
    }
    dp[0] = A[0];                // �߽�
    for(i=1; i<T; ++i) {
        // ״̬ת�Ʒ���
        dp[i] = min(A[i], dp[i-1] + A[i]);
    }
    // ��������������к�
    res = dp[0];
    for(i=1; i<T; ++i) {
        if(dp[i] < res) {
            res = dp[i];
        }
    }
    printf("%d\n", res);        // ���

    return 0;
}
