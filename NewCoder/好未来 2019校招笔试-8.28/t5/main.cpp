#include<stdio.h>
using namespace std;
int arr[100];
int maxSumIS( int arr[], int n )
{
    int i, j, max = 0;
    int dp[n];
    for ( i = 0; i < n; i++ )
        dp[i] = arr[i];
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];
    for ( i = 0; i < n; i++ )
        if ( max < dp[i] )
            max = dp[i];

    return max;
}
int main()
{
    int temp=0, i=0;
    while(~scanf("%d", &temp)){
        arr[i] = temp;
        i++;
    }
    printf("%d\n", maxSumIS(arr, 100));
    return 0;
}
