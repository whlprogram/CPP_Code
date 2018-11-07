/*
描述
小明有 n( 1<=n<=2000 )个美味的食物,他想卖掉它们来赚钱.
这些食物放在一些箱子里,他们有些有趣的特性
1. 这些食物被编号为 1~n,每一天小明可以从这些箱子的头部或者尾部取出食物去卖
2. 这些食物放得越久,年龄越大,价值越大,食物 i 有一个初始的价值 v(i)
3. 放了 a 天后年龄为 a ,食物最终价值为 v(i)*a
给定每一个食物的初始价值v(i),请求出小明卖掉它们后可以获得的最大价值,
第一天出售的食物的年龄为 1,此后每增加一天食物的年龄就加 1

输入
第 1 行:一个整数 n
第 2 到第 n+1 行:每个食物的初始价值 v(i)

输出
1 行:小明最终可以获得的最大价值

提示
样例说明：小明出售这些食物（初始价值1,3,1,5,2）的顺序为：
第一天卖掉第1个，
第二天卖掉第5个，
第三天卖掉第2个，
第四天卖掉第3个，
第五天卖掉第4个，获得最大的价值

1*1+2*2+3*3+4*1+5*5=43.

5
1 3 1 5 2
43

10
6 6 6 6 6 1 1 1 1 7
261

10
6 1 5 8 9 2 4 7 6 3
317

10
6 9 6 4 5 8 2 3 9 5
330

100
22 25 94 27 81 14 75
19 83 32 74 18 18 63
15 44 54 55 30 69 2 27
11 3 25 37 29 83 36 49
38 1 85 46 19 56 48 80
56 19 75 47 22 43 66 8
17 15 97 77 68 25 62 12
56 64 48 20 69 43 56 38
57 57 19 9 94 33 10 71 53
40 41 29 24 60 65 27 60 9
70 28 46 13 26 91 95 14 33
98 39 65 53 22 63 9 86 59 71 87
238226

100
5 33 95 9 19 77 4 74 94 67 70 84
70 65 41 3 56 93 4 31 58 63 38 85
63 54 45 48 85 6 30 79 82 79 5 47
26 85 57 46 86 58 26 8 98 81 4 83
53 71 19 96 97 20 13 90 74 26 93 14
43 3 6 54 61 20 21 35 3 58 18 9 74
67 23 67 18 32 25 17 38 86 4 94 59
11 92 21 25 72 19 80 11 74 34 2 48 17 67 10
261648
*/
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,food[2002],income[2002],day,maxIncome;
int main()
{
    memset(income,0,sizeof income);
    maxIncome=0;
    cin>>n;
    food[0]=food[n+1]=0;
    for(int i=1;i<=n;++i)
    {
        cin>>food[i];
    }
    for(int i=1;i<=n;++i)
    {
        day=i-1;
        for(int j=n;j>=i;--j)
        {
            income[j]=max(income[j]+food[i-1]*day,income[j+1]+food[j+1]*day);
            ++day;
        }
        maxIncome=max(maxIncome,income[i]+food[i]*n);
    }
    cout<<maxIncome;
    return 0;
}
*/

//income( i,j ) 表示还有第i个到第j个没卖出时，已经得到的最大收入
//income( i,j )=max( income( i-1,j )+food[i-1]*day,income( i,j+1 )+food[j+1]*day )
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,food[2002],income[2002][2002],day,maxIncome;

int main()
{
    memset(income,0,sizeof income);
    maxIncome=0;
    cin>>n;
    food[0]=food[n+1]=0;
    for(int i=1;i<=n;++i)
    {
        cin >> food[i];
    }
    for(int i=1; i<=n; ++i)
    {
        day=i-1;
        for(int j=n;j>=i;--j)
        {
            income[i][j] = max(income[i-1][j]+food[i-1]*day, income[i][j+1]+food[j+1]*day);
            ++day;
        }
        maxIncome=max(maxIncome,income[i][i]+food[i]*n);
    }
    cout << maxIncome;
    return 0;
}
