//DFS
#include <iostream>
#include <vector>
using namespace std;
int n;
int res;
void dfs(vector<vector<int>>& friends, int x, int y,vector<vector<bool>>& mark){
    if(x >=  friends.size() || y >= friends[0].size() || x < 0 || y < 0)
        return;
    if(mark[x][y] == true)
        return;
    if(friends[x][y] == 0){
        mark[x][y] = true;
        return;
    }
    // 对于已经搜索过的点要进行标记
    mark[x][y] = true;
    res--;
    for(int j=1; j<n; j++){
        dfs(friends, x, j, mark);
    }

}
void minM(vector<vector<int>>& friends) {
    if(friends.empty())
        return;
    res = n;
    vector<vector<bool>> vecMark(friends.size(),vector<bool>(friends[0].size(),false));// 定义标记数组
    //开始搜索
    for(int i = 1;i < friends.size();i++){
        for(int j = 1;j < friends[0].size();j++){
            if(vecMark[i][j] == true)
                continue;
            if(friends[i][j] == 0){
                vecMark[i][j] = true;
                continue;
            }

            dfs(friends, i, j, vecMark);
        }

    }
    cout << num << endl;
}
int main()
{
    cin >> n;
    vector<vector<int>> friends(n+1, vector<int>(n+1,0));
    int temp = 0;
    for(int i=1; i<=n; i++){
        int j = 1;
        while(cin>>temp){
            if(temp == 0)
                break;
            friends[i][j] = temp;
            j++;
        }
    }
    minM(friends);
    return 0;
}
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
