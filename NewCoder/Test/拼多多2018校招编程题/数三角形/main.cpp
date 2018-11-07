/*
‘≠Ã‚¡¥Ω” https://www.nowcoder.com/test/10628824/summary

*/
#include <iostream>
#include <cstdio>

using namespace std;
struct point{
    int x;
    int y;
};
point a[100];
int n;
int main()
{
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    int res = 0;
    for(i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if((a[j].x-a[i].x)*(a[k].y-a[i].y) - (a[k].x-a[i].x)*(a[j].y-a[i].y) != 0)
                    ++res;
            }
        }
    }
    printf("%d", res);
    return 0;
}
