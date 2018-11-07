//给出n组数据 每组数据包含一个人的面试开始时间和结束时间
//一个面试官同时时间最多面试一个人,面试完后可以继续面试下一个人
//根据给出的数据，输出最少需要面试官的数量
/*
输入：
4
940 1000
950 1030
1040 1100
1030 1340

输出:
2
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
struct Time{
    int Begin;
    int End;
};
bool tmp(Time a, Time b)
{
    if(a.Begin != b.Begin)
        return a.Begin<b.Begin;
    if(a.Begin==b.Begin && a.End != b.End)
        return a.End<b.End;
}
int main()
{
    int n;
    scanf("%d", &n);
    Time arr[n];
    for(int i=0; i<n; i++)
        scanf("%d %d", &arr[i].Begin, &arr[i].End);
    sort(arr, arr+n, tmp);
    printf("arr-----sort------\n");
    for(int i=0; i<n; i++)
        printf("%d %d\n", arr[i].Begin, arr[i].End);
    int res[n];//存放每个面试者面试时间段中最少需要面试官的数量
    for(int i=0; i<n; i++)
        res[i] = 1;
    for(int i=0; i<n; i++)
    {
        if(i!=0)//比arr[i]面试开始时间早 并且在arr[i]面试时间开始时 还没有结束面试的同学
        {
            for(int j=0; j<i; j++)
                if(arr[j].End > arr[i].Begin)
                    res[i]++;
        }
        if(i != (n-1))//比arr[i]面试开始时间晚 但是开始时间在arr[i]面试结束时间之前的同学
        {
            for(int k=i+1; k<n; k++)
                if(arr[k].Begin < arr[i].End)
                    res[i]++;
        }
    }
    int MAX = res[0];
    for(int i=1; i<n; i++)
        if(MAX < res[i])
            MAX = res[i];
    cout << MAX << endl;
    return 0;
}
