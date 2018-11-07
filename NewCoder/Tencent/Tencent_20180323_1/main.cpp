/*
输入t组数据
每组数据两行 每行四个数 第一行是四个点的横坐标 第二行是四个点的纵坐标
四个点能组成正方形输出Yes 否则输出No
1.(特殊情况)四个点有两点在同一位置  数据组t小于1
2.算法  判断四条边相等 其中一个角为直角
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    if(t<1)
        return 0;
    for(int i=0; i<t; i++){
        int a1,a2,b1,b2,c1,c2,d1,d2;
        scanf("%d %d %d %d", &a1, &b1, &c1, &d1);
        scanf("%d %d %d %d", &a2, &b2, &c2, &d2);
        int AB = (a1-b1)*(a1-b1) + (a2-b2)*(a2-b2);
        int AC = (a1-c1)*(a1-c1) + (a2-c2)*(a2-c2);
        int AD = (a1-d1)*(a1-d1) + (a2-d2)*(a2-d2);
        //printf("%d, %d, %d\n", AB, AC, AD);
        int BD = (b1-d1)*(b1-d1) + (b2-d2)*(b2-d2);
        int CD = (c1-d1)*(c1-d1) + (c2-d2)*(c2-d2);
        int BC = (b1-c1)*(b1-c1) + (b2-c2)*(b2-c2);


        if(AB==AC && AB==BD && BD==CD && AB+AC==BC){//四边相等 角BAC为直角
            printf("Yes");
        }else if(AB==AD && AB==CD && CD==BC && AB+AD==BD){
            printf("Yes");
        }else if(AC==AD && AC == BC && BC==BD && AC+AD==CD){
            printf("Yes");
        }else{
            printf("No");
        }
    }
    return 0;
}
