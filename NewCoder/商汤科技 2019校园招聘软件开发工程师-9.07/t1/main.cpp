#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
long long n, k;
long long arr[100005];
long long minArr = 9223372036854775807;
long long maxArr = -9223372036854775808;
long long minArrRe = 9223372036854775807;
long long maxArrRe = -9223372036854775808;
int main()
{
    cin >> n >> k;
    if(n == 0)
        return 0;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    long long sum = 0;
    vector<long long> arr;
    for(int i=0; i<n; i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        sum += temp;
        if(temp > maxArr)
            maxArr = temp;
        if(temp < minArr)
            minArr = temp;
    }
    sort(arr.begin(), arr.end());
    long long mid = arr.size()/2;
    for(int i=0; i<n; i++){
        if(i <= mid)
            arr[i] += k;
        else
            arr[i] -= k;
        if(arr[i] > maxArrRe)
            maxArrRe = arr[i];
        if(arr[i] < minArrRe)
            minArrRe = arr[i];
    }
    //cout << maxArr << endl;
    //cout << minArr << endl;
    long long res = maxArr - minArr;
    //cout << res << endl;
    long long temp = maxArrRe - minArrRe;
    //cout << temp << endl;
    if(res > temp)
        res = temp;
    cout << res << endl;
    return 0;
}
/*
4 3
1 7 2 5
*/
