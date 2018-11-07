//LeetCode ��200��
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
    // ���ڵ�[x,y]������������4�����Ƿ��ǵ���
    // ��[x-1,y],[x+1,y],[x,y-1],[x,y+1]
    // �����Ѿ��������ĵ�Ҫ���б��
    vis[x][y] = true;
    // ������Χ4����
    return 1 + dfs(numOfBG, x+1, y, vis) + dfs(numOfBG, x-1, y, vis) + dfs(numOfBG, x, y+1, vis) + dfs(numOfBG, x, y-1, vis);
}
void maxOfBG(vector<vector<int>>& numOfBG) {
    if(numOfBG.empty())
        return;
    int num = 0;
    //int res = 0;
    vector<vector<bool>> vis(numOfBG.size(),vector<bool>(numOfBG[0].size(),false));// ����������
    // ���������߽�
    int mostDeep = numOfBG.size();
    int mostRight = numOfBG[0].size();
    //��ʼ����
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
