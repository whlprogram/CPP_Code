/*
小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
并且小Q对于能否被3整除这个性质很感兴趣。
小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。

输入描述:
输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。

输出描述:
输出一个整数, 表示区间内能被3整除的数字个数。

输入例子1:
2 5
输出例子1:
3

例子说明1:
12, 123, 1234, 12345...
其中12, 123, 12345能被3整除。
*/
/*
从1开始计算，容易发现：
n=                true/false?
1 ……………… 0
2 ……………… 1
3 ……………… 1
4 ……………… 0
5 ……………… 1
6 ……………… 1
7 ……………… 0
证明也非常简单，几步数学归纳法即可。

所以从1到x共计有fuck(x) = (x+2)/3个不满足条件的值。
所以从l到r共计有[fuck(r) - fuck(l-1)]个不满足条件的值，把它们抠掉。

#include<stdio.h>
#define fuck(x) (((x)+2)/3)
int main(){
    int r,l;
    while(~scanf("%d%d",&l,&r))
        printf("%d\n", r-l+1-fuck(r)+fuck(l-1));
    return 0;
}


*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long start, end;
    scanf("%lld %lld", &start, &end);
    long long res = (end - start + 1 )/3*2;
    if((end - start + 1)%3 == 1){
        if(start%3 == 0)
            res += 1;
        if(start%3 == 2)
            res += 1;
    }
    if((end - start + 1)%3 == 2){
        if(start%3 == 0)
            res += 1;
        if(start%3 == 1)
            res += 1;
        if(start%3 == 2)
            res += 2;
    }

    cout << res << endl;
    return 0;
}
/*

217982186 436746452

145842845
*/
