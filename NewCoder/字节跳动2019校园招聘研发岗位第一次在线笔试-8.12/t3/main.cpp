#include <bits/stdc++.h>
#define M 110
#define MV 100100
#define INF 8888
//#define INF 0x3f3f3f3f
using namespace std;
int n;
int x[M];
int y[M];
int dp[2][2][MV];
void Update(int value, int now, int score){
    int i = 0;
    int j = value;
    if(value < 0){
        i = 1;
        j = -j;
    }
    dp[now][i][j] = max(dp[now][i][j], score);
}
int Solve(){
    int now = 0, pre = 1;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < MV; j++) {
            dp[now][i][j] = -INF;
        }
    }

    cout << "=========初始11111=start======" << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n+4; j++) {
            cout << dp[now][i][j] << " ";
        }
        cout <<endl;
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n+4; j++) {
            cout << dp[pre][i][j] << " ";
        }
        cout <<endl;
    }
    cout << "=========初始11111=end=========" <<endl;

    dp[now][0][0] = 0;
    for (int i = 0; i < n; i++){



        swap(now, pre);
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < MV; k++){
                dp[now][j][k] = -INF;
            }
        }

int www=0;
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < MV; k++){
                if (dp[pre][j][k] == -INF){
                    continue;
                }
                dp[now][j][k] = max(dp[now][j][k], dp[pre][j][k]);
                int value = k;
                if(j){
                    value = -value;
                }

                cout << "=========内循环11111=www=" << www << endl;
                cout << "i= " << i << endl;
                cout << "j= " << j << endl;
                cout << "k= " << k << endl;
                cout << "value= " << value << endl;
                cout << "now= " << now << endl;
                cout << "pre= " << pre << endl;
                for (int w = 0; w < 2; w++){
                    for (int h = 0; h < n+4; h++) {
                        cout << dp[0][w][h] << " ";
                    }
                    cout <<endl;
                }
                for (int w = 0; w < 2; w++){
                    for (int h = 0; h < n+4; h++) {
                        cout << dp[1][w][h] << " ";
                    }
                    cout <<endl;
                }
                cout << "=========循环=end=========" <<endl;

                Update(value + x[i], now, dp[pre][j][k] + y[i]);

                cout << "=========内循环22222=www=" << www << endl;
                for (int w = 0; w < 2; w++){
                    for (int h = 0; h < n+4; h++) {
                        cout << dp[0][w][h] << " ";
                    }
                    cout <<endl;
                }
                for (int w = 0; w < 2; w++){
                    for (int h = 0; h < n+4; h++) {
                        cout << dp[1][w][h] << " ";
                    }
                    cout <<endl;
                }
                cout << "=========循环=end=========" <<endl;

                Update(value - x[i], now, dp[pre][j][k] + y[i]);

                cout << "=========内循环33333=www=" << www << endl;
                for (int w = 0; w < 2; w++){
                    for (int h = 0; h < n+4; h++) {
                        cout << dp[0][w][h] << " ";
                    }
                    cout <<endl;
                }
                for (int w = 0; w < 2; w++){
                    for (int h = 0; h < n+4; h++) {
                        cout << dp[1][w][h] << " ";
                    }
                    cout <<endl;
                }
                www++;
                cout << "=========循环=end=========" <<endl;
            }
        }
        cout << "=========循环=i=" << i << endl;
        for (int w = 0; w < 2; w++){
            for (int h = 0; h < n+4; h++) {
                cout << dp[0][w][h] << " ";
            }
            cout <<endl;
        }
        for (int w = 0; w < 2; w++){
            for (int h = 0; h < n+4; h++) {
                cout << dp[1][w][h] << " ";
            }
            cout <<endl;
        }
        cout << "=========循环=end=========" <<endl;
    }
    return dp[now][0][0];
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    printf("%d\n", Solve());

    /*
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        printf("%d\n", Solve());
    }
    */
/*
4
3 1
2 2
1 4
1 4
*/
    return 0;
}
