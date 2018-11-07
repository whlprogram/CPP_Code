#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int q=0; q<T; q++){
        int N,X,Y;
        scanf("%d %d %d", &N, &X, &Y);
        int arr[N][2];
        for(int i=0; i<N; i++){
            cin >> arr[i][0];
            cin >> arr[i][1];
        }
        for(int i=0; i<N-1; i++){
            for(int j=1; j<N; j++){
                if(arr[j][0] > arr[i][0]){
                    int temp0 = arr[i][0];
                    int temp1 = arr[i][1];

                    arr[i][0] = arr[j][0];
                    arr[i][1] = arr[j][1];

                    arr[j][0] = temp0;
                    arr[j][1] = temp1;
                }
                if(arr[j][0] == arr[i][0] && arr[j][1] < arr[i][1]){
                    int temp0 = arr[i][0];
                    int temp1 = arr[i][1];

                    arr[i][0] = arr[j][0];
                    arr[i][1] = arr[j][1];

                    arr[j][0] = temp0;
                    arr[j][1] = temp1;
                }
            }
        }
        int minx = arr[X-1][0];
        for(int i=0; i<N-1; i++){
            for(int j=1; j<N; j++){
                if(arr[j][1] > arr[i][1]){
                    int temp0 = arr[i][0];
                    int temp1 = arr[i][1];

                    arr[i][0] = arr[j][0];
                    arr[i][1] = arr[j][1];

                    arr[j][0] = temp0;
                    arr[j][1] = temp1;
                }
                if(arr[j][1] == arr[i][1] && arr[j][0] < arr[i][0]){
                    int temp0 = arr[i][0];
                    int temp1 = arr[i][1];

                    arr[i][0] = arr[j][0];
                    arr[i][1] = arr[j][1];

                    arr[j][0] = temp0;
                    arr[j][1] = temp1;
                }
            }
        }
        int miny = arr[Y-1][1];
        cout << (minx>miny ? miny : minx) << endl;
    }
    return 0;
}
