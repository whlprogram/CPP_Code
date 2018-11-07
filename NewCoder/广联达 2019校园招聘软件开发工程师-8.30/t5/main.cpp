//求数组中最大升序子序列
#include <iostream>
#include <vector>
using namespace std;
int maxIS(vector<int> arr, int n){
    int i, j, max=0;
    int dp[n];
    for(i=0; i<n; i++)
        dp[i] = 1;
    for(i=1; i<n; i++){
        for(j=0; j<i; j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1)
                dp[i] = dp[j] + 1;
        }
    }
    for(i=0; i<n; i++){
        if(max < dp[i])
            max = dp[i];
    }
    return max;
}
int main()
{
    int temp=0, n=0;
    vector<int> arr;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    cout << maxIS(arr, n) << endl;
    return 0;
}
