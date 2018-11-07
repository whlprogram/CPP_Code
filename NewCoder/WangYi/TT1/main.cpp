#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int q=0; q<T; q++){
        int N,M;
        scanf("%d %d", &N, &M);
        int temp = M/N;
        if(M%N%2 != 0)
            temp --;
        int len = (temp+2)*N;
        char arr[len][len];
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++)
                arr[i][j] = '*';
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                char c;
                cin >> c;
                arr[i][j] = c;
            }
        }
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                arr[i][j] = arr[i%N][j%N];
            }
        }
        int res = (N-(M-temp*N)/2);
        for(int i=res; i<len-res; i++){
            for(int j=res; j<len-res; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
