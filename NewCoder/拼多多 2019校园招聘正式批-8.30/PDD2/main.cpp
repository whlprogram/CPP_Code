#include <iostream>
#include <cstring>

using namespace std;


int main(){
    int n, m;//N�� M��
    cin >> n >> m;
    char board[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < m; i++){//���д���
        bool flag = false;
        int xLine = -1;//��¼x���ڵ���
        int cnt = 0;//cnt��¼o������
        for(int j = n -1; j >= 0; j--){//���µ��� ���д���
            if(!flag && board[j][i] == 'o'){//û����x֮ǰ oȫ�����
                board[j][i] = '.';
            }else if(board[j][i] == 'x'){
                flag = true;
                xLine = j;
                cnt = 1;
            }else if(board[j][i] == 'o'){
                //cout << j << " " << i << endl;
                board[xLine - cnt][i] = 'o';//����λ�� ��Ϊo
                if(xLine - cnt != j){//���o����  �ͽ�oԭ��λ����Ϊ.
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
