/*
原题链接 https://www.nowcoder.com/test/10628824/summary

*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
struct bear{
    int id;
    int fight;
    int hunger;
    friend bool operator < (bear a, bear b){
        return a.fight > b.fight;
    }
};
bool tmp(bear a, bear b){
        return a.fight > b.fight;
}
int n, m; //n只小熊 m个糖
int a[100];//糖能补充饥饿值的能量
bear b[10];//小熊
int v[100];//糖是否被吃
int res[10];//最终输出
int main()
{
    scanf("%d%d", &n, &m);
    int i;
    for(i=0; i<m; i++)
        scanf("%d", a+i);
    for(i=0; i<n; i++){
        scanf("%d %d", &b[i].fight, &b[i].hunger);
        b[i].id = i;
    }
    //sort(b, b+n, tmp);
    sort(b, b+n);//小熊按战斗力从大到小排序
    /*
    for(i=0; i<n; i++){
        printf("%d %d %d\n", b[i].id, b[i].fight, b[i].hunger);
    }
    */
    for(i=0; i<n; i++){
        int index = -1;//代表小熊b[i]下一个要吃的能量最大的糖的编号
        for(int j=0; j<m; j++){//寻找index
            if(!v[j] && b[i].hunger>=a[j] && (index==-1 || a[j]>a[index]))
                index = j;
        }
        if(index != -1){//找到index
            b[i].hunger -= a[index];
            v[index] = 1;
            --i;//下次外层循环继续寻找该小熊能吃的最大的糖
        }else{//找不到，小熊已经不能再吃了
            res[b[i].id] = b[i].hunger;//存储小熊剩余饥饿值
        }
    }
    for(i=0; i<n; i++){
        printf("%d\n", res[i]);
    }
    return 0;
}
