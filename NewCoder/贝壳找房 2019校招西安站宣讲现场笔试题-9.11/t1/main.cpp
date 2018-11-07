#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int n, m;//n站点 m班公交
    cin >> n >> m;
    int arr[n+1];//记录站点停靠公交数量公交
    int arr_s[n+1];//记录公交起始点
    int arr_t[n+1];//记录公交结束点
    memset(arr, 0, sizeof(arr));
    memset(arr_s, 0, sizeof(arr_s));
    memset(arr_t, 0, sizeof(arr_t));
    bool flag = true;
    for(int i=0; i<m; i++){
        int temp_s, temp_t;
        cin >> temp_s >> temp_t;
        if(temp_t == n)
            flag = false;
        arr_s[temp_s] += 1;
        arr_t[temp_t] += 1;
        for(int j=temp_s; j<=temp_t; j++)
            arr[j] += 1;
    }
    int count = 0;
    for(int i=0; i<=n; i++){
        cout << arr[i]  << " ";
    }
    cout << endl;

    if(flag){//所有公交车均不到公司
        cout << 0 << endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        if(arr_s[i] != 0 && arr_t[i] != 0){
            if(arr_s[i] == 1 && arr_t[i] == 1)
                arr[i]--;
            if(arr_s[i] >= 2)
                arr[i] -= (arr_s[i]-1);
            if(arr_t[i] >= 2)
                arr[i] -= (arr_t[i]-1);
        }
        if(arr[i] == 0){
            //中间断流
            cout << 0 << endl;
            return 0;
        }else{
            if(i!=0 && i!=n && arr[i]>1){
                count++;
            }
        }
    }
    cout << pow(2, count) << endl;
    return 0;
}
/*
2 2
0 1
1 2

3 2
0 1
1 2

5 5
0 1
0 2
0 3
0 4
0 5

5 5
0 1
1 2
2 3
2 4
4 5

20 5
7 15
0 6
14 18
0 8
17 20

*/
