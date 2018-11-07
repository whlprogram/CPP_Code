//迷宫寻路
#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
char G[105][105];
int book[105][105][1200],N,M;
int Next[4][2]={0,1,0,-1,1,0,-1,0};
int bfs(int,int);
struct node{
    int x,y,k,step;
    node(int x,int y,int k,int step):x(x),y(y),k(k),step(step){}
};
int main(){
    int i,j;
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&N,&M)!=EOF){
        for(i=0;i<N;i++) scanf("%s",G[i]);
        memset(book,0,sizeof(book));
        int flag=0;
        for(i=0;i<N;i++){
            if(flag==1) break;
            for(j=0;j<M;j++)
                if(G[i][j]=='2'){
                    flag=1;
                    book[i][j][0]=1;
                    printf("%d\n",bfs(i,j));
                    break;
                }
        }
    }
}
int bfs(int startX,int startY){
    queue<node> Q;
    Q.push(node(startX,startY,0,0));
    while(!Q.empty()){
        node head=Q.front();Q.pop();
        if(G[head.x][head.y]=='3') return head.step;
        for(int i=0;i<4;i++){
            int nx=head.x+Next[i][0],ny=head.y+Next[i][1];
            if(nx>=N||nx<0||ny>=M||ny<0||G[nx][ny]=='0') continue;
            int key=head.k;
            if('a'<=G[nx][ny]&&G[nx][ny]<='z') key=key|(1<<(G[nx][ny]-'a'));
            if('A'<=G[nx][ny]&&G[nx][ny]<='Z'&&(key&(1<<(G[nx][ny]-'A')))==0) continue;
            if(!book[nx][ny][key]){
                book[nx][ny][key]=1;
                Q.push(node(nx,ny,key,head.step+1));
            }
        }
    }
    return 0;
}//这题就是普通的bfs多了‘钥匙’这个状态
 //所以book[x][y][key]的意义就是 横坐标为x,纵坐标为y,钥匙状态为key的点是否访问过
 //钥匙的状态 就用二进制数表示 最多10 把钥匙 那就是1024
 //比如我现在有第二把钥匙和第四把钥匙  那么我的钥匙状态就是 0101000000 也就是 320






//大数乘法
//逐位相乘法
//将计算的整体结果保存res中，然后再考虑进位
string Mul2(string left,string right)
{
    size_t lSize = left.size();
    size_t Rsize = right.size();
    size_t Size = lSize + Rsize;
    vector<int> res(Size, 0);
    /*int *res = new int[Size];
    memset(res, 0, sizeof(int)* Size);*/


    for (size_t i = 0; i < Rsize; ++i)
    {
        int rightnum = right[Rsize - i - 1] - '0';
        for (size_t j = 0; j < lSize; ++j)
        {
            int num = rightnum * (left[lSize - j - 1] - '0');
            //逆序存放
            res[Size - 1 -(i + j)] += num;
        }
    }
    //处理进位
    int takeover = 0;
    size_t idx = 0;
    for (; idx < Size; ++idx)
    {
        int temp = res[Size - idx - 1] + takeover;
        res[Size - idx - 1] = temp % 10;
        takeover = temp / 10;
    }
    //进位没有处理完
    while (takeover != 0)
    {
        res[Size - idx - 1] = takeover % 10 ;
        takeover /= 10;
    }

    //处理返回结果
    string result;
    for (size_t index = 0; index < Size; ++index)
    {
        result += res[index] + '0';
    }
    //如果没有进位的话，res最高位没有数字
    if (result[0] == 0)
        result.erase(0, 1);

    return result;
}
int main()
{
    string data;
    getline(cin, data);
    size_t pos = data.find(' ');
    string left = data.substr(0, pos);
    string right = data.substr(pos + 1);
    string res = Mul2(left, right);
    cout << res << endl;
    system("pause");
    return 0;
}



//六一儿童节
//AC代码:
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int N,M,i,j;
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    vector<int> child(N);
    for(i=0;i<N;i++) scanf("%d",&child[i]);
    scanf("%d",&M);
    vector<int> cho(M);
    for(i=0;i<M;i++) scanf("%d",&cho[i]);
    sort(child.begin(),child.end());
    sort(cho.begin(),cho.end());
    int res=0;
    for(i=0,j=0;i<M&&j<N;i++)
        if(cho[i]>=child[j])
            res++,j++;
    printf("%d\n",res);
}
