//LeetCode 第200题
#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>& numOfBG, int x, int y,vector<vector<bool>>& vis){
    if(x >=  numOfBG.size() || y >= numOfBG[0].size() || x < 0 || y < 0)
        return 0;
    if(vis[x][y] == true)
        return 0;
    if(numOfBG[x][y] == 0)
        return 0;
    // 对于点[x,y]搜索上下左右4个点是否是岛屿
    // 即[x-1,y],[x+1,y],[x,y-1],[x,y+1]
    // 对于已经搜索过的点要进行标记
    vis[x][y] = true;
    // 遍历周围4个点
    return 1 + dfs(numOfBG, x+1, y, vis) + dfs(numOfBG, x-1, y, vis) + dfs(numOfBG, x, y+1, vis) + dfs(numOfBG, x, y-1, vis);
}
void maxOfBG(vector<vector<int>>& numOfBG) {
    if(numOfBG.empty())
        return;
    int num = 0;
    //int res = 0;
    vector<vector<bool>> vis(numOfBG.size(),vector<bool>(numOfBG[0].size(),false));// 定义标记数组
    // 定义搜索边界
    int mostDeep = numOfBG.size();
    int mostRight = numOfBG[0].size();
    //开始搜索
    for(int i = 0;i < mostDeep;i++){
        for(int j = 0;j < mostRight;j++){
            if(vis[i][j] == true)
                continue;
            if(numOfBG[i][j] == 0){
                vis[i][j] = true;
                continue;
            }
            dfs(numOfBG, i, j, vis);
            int temp = dfs(numOfBG, i, j, vis);
            ++num;
            //grid[i][j] = 8;
            //res = res>temp ? res : temp;
        }
    }
    cout << num << endl;
}

int main()
{
    int m;
    cin >> m;
    vector<vector<int>> numOfBG(m, vector<int>(m,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin >> numOfBG[i][j];
        }
    }
    maxOfBG(numOfBG);
    return 0;
}
