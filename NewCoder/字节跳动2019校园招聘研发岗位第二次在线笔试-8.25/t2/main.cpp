//���鼯

#include <stdio.h>
#define N 100020
int friends[N];//ÿ������������ͨ������������������ʱÿ���˵ĸ��ڵ�
int rank[N];//��ͨ������Ȩֵ�����������Ĵ�С
int res;
void init(int n)//��ʼ��initialization
{
    for(int i=0;i<n;i++)
    {
        friends[i]=i;
        rank[i]=0;
    }
}

int findRoot(int x)//Ѱ��x�������������ĸ��ڵ�
{
    //һֱ���ϱ���Ѱ�Ҹ��ڵ�
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
    //�ж����ߣ�С�����ڴ�����
    if(rank[xRoot] < rank[yRoot])
        friends[xRoot]=yRoot;
    else
    {
        friends[yRoot] = xRoot;
        if(rank[xRoot]==rank[yRoot])//��������ȣ��ϲ�������+1
            rank[xRoot]++;
    }
    --res;
}
int main()
{
   	int n;
    init(N);//��ʼ��
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
