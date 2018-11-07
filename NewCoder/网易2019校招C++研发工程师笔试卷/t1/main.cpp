#include <iostream>
#include <cstdio>

using namespace std;
int n;
int a[1005];
int arr[1005];
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        arr[i] = arr[i-1]  + a[i];
    }
    int m;
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        int q;
        scanf("%d", &q);
        int l=0, r=n;
        while(l <= r){
            int mid = (l+r)/2;
            if((mid==0 && q<=arr[0]) || (arr[mid-1]<q && q<=arr[mid])){
                printf("%d\n", mid);
                break;
            }else if( q > arr[mid]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }

        }
    }
    return 0;
}
