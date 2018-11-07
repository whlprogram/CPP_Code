#include <iostream>
#include <cstring>

using namespace std;


int main(){
    int n, m;//N行 M列
    cin >> n >> m;
    char board[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < m; i++){//按列处理
        bool flag = false;
        int xLine = -1;//记录x所在的行
        int cnt = 0;//cnt记录o的数量
        for(int j = n -1; j >= 0; j--){//从下到上 按行处理
            if(!flag && board[j][i] == 'o'){//没碰到x之前 o全部清除
                board[j][i] = '.';
            }else if(board[j][i] == 'x'){
                flag = true;
                xLine = j;
                cnt = 1;
            }else if(board[j][i] == 'o'){
                //cout << j << " " << i << endl;
                board[xLine - cnt][i] = 'o';//掉落位置 置为o
                if(xLine - cnt != j){//如果o掉落  就将o原来位置清为.
                    board[j][i] = '.';
                }
                cnt++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
/*
3 4
.oxo
o..o
.xox
*/
