/*
玥玥带乔乔一起逃亡,现在有许多东西要放到乔乔的包里面,
但是包的大小有限,所以我们只能够在里面放入非常重要的物品.
现在给出该种物品的数量,体积,价值的数值,
希望你能够算出怎样能使背包的价值最大的组合方式,
并且输出这个数值,乔乔会非常感谢你的
对于30%的数据
1<=n<=2000 1<=v<=500
1<=m<=10 1<=w<=20 1<=s<=100

输入
第 1 行有两个整数,物品种数 n 和背包装载体积v;
第 2 到 n+1 行每行三个整数,为第 i 种物品的数量m, 体积w,价值s
输出
仅包含一个整数,即为能拿到的最大的物品价值总和

Input
2 10
3 4 3
2 2 5
Output
13

参考链接 http://bestmind.space/posts/%E9%93%BE%E5%AE%B62018%E9%93%BE%E4%B9%A0%E7%94%9F%E6%8B%9B%E8%81%98%E8%80%83%E8%AF%95-%E7%BC%96%E7%A8%8B%E9%A2%98%E4%B8%80/
*/
#include <iostream>
#include <bits/stdc++.h>//包含C++的所有头文件
using namespace std;

int n, v, m, w[20001], s[20001];
int c=0;//c为物品总个数
int res[20001][501];//res[i][j]表示物品为1到i个，体积为j的情况下背包最大价值 空间复杂度O(c*v)
int simple[501];//simple[v]表示物品为1到c个，体积为v的情况下背包最大价值 空间复杂度减小到O(v)
//空间复杂度减小到O(v)
int main()
{
    memset(simple,0,sizeof simple);//对value清零
    scanf("%d %d", &n, &v);
    for(int i=1,j=1; i<=n; i++){
        scanf("%d %d %d", &m, &w[j], &s[j]);
        c += m;
        for(int k=1; k<m; k++){
            w[j+k] = w[j];
            s[j+k] = s[j];
        }
        j += m;
    }
    for(int i=1; i<=c; i++){
        for(int j=v; j>=0; j--){
            int k = j-w[i];
            simple[j] = (k>=0 ? max(simple[k]+s[i], simple[j-1]) : simple[j-1]);
        }
        //for(int q=0; q<=v; q++){
        //    cout << simple[q] << " ";
        //}
        //cout << endl;
    }
    cout << simple[v] << endl;
    return 0;
}

/*空间复杂度O(c*v)
int main()
{
    memset(res,0,sizeof res);//对value清零
    scanf("%d %d", &n, &v);
    for(int i=1,j=1; i<=n; i++){
        scanf("%d %d %d", &m, &w[j], &s[j]);
        c += m;
        for(int k=1; k<m; k++){
            w[j+k] = w[j];
            s[j+k] = s[j];
        }
        j += m;
    }
    for(int i=1; i<=c; i++){
        for(int j=1; j<=v; j++){
            int k = j-w[i];
            res[i][j] = (k>=0 ? max(res[i-1][k]+s[i], res[i-1][j-1]) : res[i-1][j-1]);
        }
    }
    //for(int i=0; i<=c; i++){
    //    for(int j=0; j<=v; j++){
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    cout << res[c][v] << endl;
    return 0;
}
*/
