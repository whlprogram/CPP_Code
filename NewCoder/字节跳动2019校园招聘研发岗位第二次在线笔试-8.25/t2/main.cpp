//并查集

#include <stdio.h>
#define N 100020
int friends[N];//每个人所属的连通分量，即构成朋友树时每个人的父节点
int rank[N];//连通分量的权值，即朋友树的大小
int res;
void init(int n)//初始化initialization
{
    for(int i=0;i<n;i++)
    {
        friends[i]=i;
        rank[i]=0;
    }
}

int findRoot(int x)//寻找x所属的朋友树的根节点
{
    //一直向上遍历寻找根节点
    while(x != friends[x])
        x = friends[x];
    return x;
}

void connect(int x,int y)
{
    int xRoot = findRoot(x);
    int yRoot = findRoot(y);
    if(xRoot == yRoot)
        return ;
    //判断树高，小树并在大树下
    if(rank[xRoot] < rank[yRoot])
        friends[xRoot]=yRoot;
    else
    {
        friends[yRoot] = xRoot;
        if(rank[xRoot]==rank[yRoot])//两树高相等，合并后树高+1
            rank[xRoot]++;
    }
    --res;
}
int main()
{
   	int n;
    init(N);//初始化
    scanf("%d",&n);
    res = n;
    for(int i=1;i<=n;i++){
    	int t;
    	while(~scanf("%d",&t)){
    		if(t == 0)
                break;
    		connect(i,t);
		}
	}
	printf("%d",res);
/*
10
0
5 3 0
8 4 0
9 0
9 0
3 0
0
7 9 0
0
9 7 0
*/
    return 0;
}
