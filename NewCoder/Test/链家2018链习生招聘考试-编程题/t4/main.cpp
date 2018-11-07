/*
在迷迷糊糊的大草原上，小红捡到了n根木棍，第i根木棍的长度为i，小红现在很开心。
她想选出其中的三根木棍组成美丽的三角形。
但是小明想捉弄小红，想去掉一些木棍，使得小红任意选三根木棍都不能组成三角形。
请问小明最少去掉多少根木棍呢？
输入
本题包含若干组测试数据。

对于每一组测试数据。
第一行一个n，表示木棍的数量。

满足 1<=n<=100000

输出
输出最少数量

样例输入
4
样例输出
1

本题思路也很简单，其实就是一个斐波那契数列的问题
因为有多组参数，所以先用打表法，先求出100000以内从1、2、3开始的斐波那契数列
然后进行根据输入的n，查找小于等于n的斐波那契数列元素有res个，最终输出结果就是n-res。

注意本题是多组输入。
*/
#include <iostream>
#include <vector>
#define TOP 100000
using namespace std;

int main()
{
    vector<int> res = {0, 1, 2};
    for(int i=3; res[i-1]+res[i-2]<=TOP; i++)
        res.push_back(res[i-1]+res[i-2]);
    for(int n; cin>>n; ){//多组输入
        //函数lower_bound()在first和last中的前闭后开区间进行二分查找，返回大于或等于val的第一个元素位置。
        //如果所有元素都小于val，则返回last的位置
        vector<int>::iterator it = lower_bound(res.begin(), res.end(), n);
        int temp = (*it==n ? 0 : *it-n-1);//没有在斐波那契数列中找到n，减去temp
        cout << *it - (it-res.begin()) - temp << endl;
    }
    return 0;
}
