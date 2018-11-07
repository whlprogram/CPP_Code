#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k;
int dp[1002][1001];
int v[1001];
int main()
{
    cin >> n >> k;
    for(int i=0; i<k; i++)
        cin >> v[i];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<k; i++)
        dp[0][i] = 1;
    dp[0][v[0]-1] = 0;
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j] == 1){
                if(j == 0)
                    dp[i+1][j+1] = 1;
                else if(j == (n-1))
                    dp[i+1][j-1] = 1;
                else{
                    dp[i+1][j-1] = 1;
                    dp[i+1][j+1] = 1;
                }
            }
            dp[i+1][v[i+1]-1] = 0;
        }
    }
    int flag = 1;
    for(int i=0; i<n; i++){
        if(dp[k][i] == 1){
            flag = 0;
            break;
        }
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
