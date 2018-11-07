#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int dis,to;
    bool friend operator <(Edge x1,Edge x2)
    {
        return x1.dis>x2.dis;
    }
}temp,now;
vector <Edge> vec[10005];
bool life[10005];
int dis[10005],n;
priority_queue <Edge> q;

void init()
{
    for(int i=1;i<=n;i++)
        dis[i]=100000000;
    memset(life,0,sizeof(life));
    while(!q.empty())
        q.pop();
}
int dij(int s,int t)
{
    init();
    temp.to=s;
    temp.dis=0;
    q.push(temp);
    dis[s]=0;
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(!life[now.to])
        {
            life[now.to]=1;
            for(int i=0;i<vec[now.to].size();i++)
            {
                if(!life[vec[now.to][i].to] && dis[now.to]+vec[now.to][i].dis<dis[vec[now.to][i].to])
                {
                    dis[vec[now.to][i].to]=dis[now.to]+vec[now.to][i].dis;
                    temp.to=vec[now.to][i].to;
                    temp.dis=dis[vec[now.to][i].to];
                    q.push(temp);
                }
            }
        }
    }
    return dis[t];
}

int main()
{
    int m,s,t,u,v,d;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&d);
        temp.dis=d;
        temp.to=v;
        vec[u].push_back(temp);
    }
    printf("%d\n",dij(s,t)+dij(t,s));
    return 0;
}
