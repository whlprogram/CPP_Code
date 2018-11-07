/*
描述
小明喜欢在火车旅行的时候用手机听音乐，
他有 N 首歌在手机里，在整个火车途中，他可以听 P 首歌，
所以他想产生一个播放表产生 P 首歌曲，这个播放表的规则是：
· 每首歌都要至少被播放一次
· 在两首一样的歌中间，至少有M首其他的歌
迈克在想有多少种不同的播放表可以产生，
那么给你 N,M,P,你来算一下，
输出结果取1000000007的余数
输入
输入 N,M,P
N 范围在 1 到 100
M 范围在 0 到 N
P 范围在 N 到 100
输出
输出结果 mod 1000000007 的余数

Input
1 0 3
Output
1
*/
/*
定义 List(i,j) 为安排到列表为 i 首歌时已经用了 j 首不同歌的安排的种类数
当 j>i 时,萝卜多坑少,所以种类数为0
当 j==i 时,当然是全排列 A(n,n)
当 j>m 时就可以出现重复了,有两种安排方法,添加新歌,添加重复歌,所以其值就是这两种情况的和
    添加新歌
        List[i][j] = List[i-1][j-1]*(n-j+1)；
    添加重复歌
        当 j<=n 时添加重复歌曲的种类为 songList(i-1,j)*(j-m)
        当 j>n 时添加重复歌曲的种类为 songList(i-1,j)*(n-m), 因为一共就 n 首歌
最后List(n,p) 即为所求
*/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
using namespace std;

ll n,m,p,List[105][105],songList[105];
int main()
{
    while(cin >> n >> m >> p){
        memset(List, 0, sizeof List);
        List[0][0] = 1;//为了计算全排列设置的值
        for(ll i=1; i<=p; i++){//列表
            for(ll j=1; j<=n; j++){//歌
                if(j > i){//歌比列表多
                    List[i][j] = 0;
                }else if(j == i){
                    List[i][j] = List[i-1][j-1]*(n-j+1);
                }else if(j > m){
                    List[i][j] = List[i-1][j-1]*(n-j+1) + List[i-1][j]*(min(j,n)-m);
                }else{
                    List[i][j] = 0;
                }
                if(List[i][j] >= inf)
                    List[i][j] %= inf;
            }
        }
        for(ll i=0; i<=p; i++){//列表
            for(ll j=0; j<=n; j++){//歌
                   cout << List[i][j] << " ";
            }
            cout << endl;
        }
        cout << List[p][n] << endl;
    }

    return 0;
}
/*
//空间复杂度为O(n)
int main()
{
    while(cin>>n>>m>>p)
    {
        memset(songList,0,sizeof songList);
        songList[0]=1;
        for(ll i=1;i<=p;++i)
        {
            for(ll j=n;j>=0;--j)
            {
                if(j>i)
                    songList[j]=0;
                else if(j==i)
                    songList[j]=songList[j-1]*(n-j+1);
                else if(j>m)
                    songList[j]=songList[j-1]*(n-j+1)+songList[j]*(min(j,n)-m);
                else
                    songList[j]=0;
                if(songList[j]>=inf) songList[j]%=inf;
            }
            for(ll j=0;j<=n;++j)
            {
                cout<<songList[j] << " ";
            }
            cout << endl;
        }
        cout<<songList[n]<<endl;
    }
    return 0;
}
*/



