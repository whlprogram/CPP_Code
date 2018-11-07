#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>& grid, int x, int y,vector<vector<bool>>& mark){
    if(x >=  grid.size() || y >= grid[0].size() || x < 0 || y < 0)
        return 0;
    if(mark[x][y] == true)
        return 0;
    if(grid[x][y] == 0)
        return 0;
    // 对于点[x,y]搜索上下左右4个点是否是岛屿
    // 即[x-1,y],[x+1,y],[x,y-1],[x,y+1]
    // 对于已经搜索过的点要进行标记
    mark[x][y] = true;
    return 1 + dfs(grid, x+1, y, mark) + dfs(grid, x-1, y, mark) + dfs(grid, x, y+1, mark) + dfs(grid, x, y-1, mark)
            + dfs(grid, x+1, y+1, mark) + dfs(grid, x-1, y-1, mark) + dfs(grid, x+1, y-1, mark) + dfs(grid, x-1, y+1, mark);
}
void maxAreaOfIsland(vector<vector<int>>& grid) {
    if(grid.empty())
        return;
    int num = 0;
    int res = 0;
    vector<vector<bool>> vecMark(grid.size(),vector<bool>(grid[0].size(),false));// 定义标记数组
    // 定义搜索边界
    int mostDeep = grid.size();
    int mostRight = grid[0].size();
    //开始搜索
    for(int i = 0;i < mostDeep;i++){
        for(int j = 0;j < mostRight;j++){
            if(vecMark[i][j] == true)
                continue;
            if(grid[i][j] == 0){
                vecMark[i][j] = true;
                continue;
            }
            int temp = dfs(grid, i, j, vecMark);
            ++num;
            //grid[i][j] = 8;
            res = res>temp ? res : temp;
        }
    }
    cout << num << ',' << res << endl;

    /*
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size()-1; j++){
            cout << grid[i][j] << ',';
        }
        cout << grid[i][grid[0].size()-1] << endl;
    }
    */
}

int main()
{
    int x,y;
    char c;
    cin >> x >> c >> y;
    vector<vector<int>> grid(x, vector<int>(y,0));
    int temp;
    for(int i=0; i<x; i++){
        for(int j=0; j<y-1; j++){
            cin >> grid[i][j];
            cin >> c;
        }
        cin >> grid[i][y-1];
    }
    maxAreaOfIsland(grid);
    return 0;
}
