/*
本来是在全局序列之中求最长上升子序列,但是因为是重复的序列，
其实只需在第一个序列之中求最长上升序列，并且其中的最大元素在后面的每个序列之中一定存在，
最后加上b-1(b为重复序列个数)
ans[] 存储给定序列
tmp[i] 表示从第0位到第i位的最长子序列个数

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    int a,b;
    scanf("%d%d", &a, &b);
    vector<int> ans(a, 0),tmp(a,1);
    for (int i = 0;i<a;i++)
    {
        scanf("%d", &ans[i]);
    }
    for (int i = 1;i<a;i++)
    {
        for (int j = 0;j<i;j++)
        {
            if (ans[i]>=ans[j])
            {
                tmp[i] = max(tmp[i], tmp[j] + 1);
            }
        }
    }
    cout << *max_element(tmp.begin(), tmp.end())+b-1;
    return 0;
}
