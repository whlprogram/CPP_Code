#include <iostream>

using namespace std;

void fun(long long x, long long k){
    long long y = 0, n =1;
    while(k > 0){
        if(x%2 != 0){//此时x的二进制最右端为1
            while(x%2 != 0){//一直使x右移，找到x的为0的位置
                n = n*2;  //每移一位，n记录一下变化的值
                x = x/2;
            }
        }
        //如果k的二进制最右端为1，就使y加上n
        if(k%2 != 0)
            y = y+n;
        n = n*2;
        x = x/2;
        k = k/2; //同时使x,k右移，以便下一步判断
    }
    cout << y;
}

int main() {
    long long t, x, k;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> x >> k;
        fun(x, k);
        if(i != t-1)
            cout << ndl;
    }
    return 0;
}
