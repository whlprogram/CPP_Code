#include <bits/stdc++.h>

using namespace std;
int MAX(int a, int b){
    return a > b ? a : b;
}
vector<int> primes(int n){//得到小于n的质数数组
    vector<int> res;
    vector<bool> arr(n+1, false);
    for(int i = 2; i <= n; i++){
        if(!arr[i]){
            for (int j=2*i; j<=n; j+=i)
                arr[j] = true;
            res.push_back(i);
        }
    }
    return res;

}
int exponent(int a, int b){//求指数
    int res = 0;
    while(a%b == 0){
        a /= b;
        res++;
    }
    return res;
}
int getMin(int n){
    int res = 2;
    vector<int> arr = primes(n);
    for(int i=0; i<arr.size(); i++){
        int maxExponent = 0;
        int temp = arr[i];
        while(temp <= n) {
            maxExponent = MAX(maxExponent, exponent(temp, arr[i]));
            temp += arr[i];
        }
        while (exponent(temp, arr[i]) < maxExponent){
            temp += arr[i];
        }
        res = MAX(res, temp);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << getMin(n) << endl;
    return 0;
}
