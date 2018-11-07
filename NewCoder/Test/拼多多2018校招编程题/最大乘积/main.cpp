/*
‘≠Ã‚¡¥Ω” https://www.nowcoder.com/test/10628824/summary

*/
#include <iostream>
#include <cstdio>
using namespace std;
long long maxProduct(long long a[], int n){
    long long max1,max2,max3,min1,min2,product;
    max1 = a[0]>=a[1] ? a[0] : a[1];
    max2 = a[0]<a[1]  ? a[0] : a[1];
    if(a[2] > max1){
        max3 = max2;
        max2 = max1;
        max1 = a[2];
    }else if(a[2] > max2){
        max3 = max2;
        max2 = a[2];
    }else{
        max3 = a[2];
    }
    min1 = max3;
    min2 = max2;
    for(int i=3; i<n; i++){
        if(a[i] < min1){
            min2 = min1;
            min1 = a[i];
        }else if(a[i] < min2){
            min2 = a[i];
        }
        if(a[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        }else if(a[i] > max2){
            max3 = max2;
            max2 = a[i];
        }else if(a[i] > max3){
            max3 = a[i];
        }
    }
    product = max1*max2*max3 > max1*min1*min2 ? max1*max2*max3 : max1*min1*min2;
    return product;
}
int main()
{
    int n;
    scanf("%d", &n);
    long long a[n];
    int i;
    for(i=0; i<n; i++)
        scanf("%lld", &a[i]);
    printf("%lld\n", maxProduct(a, n));
    return 0;
}
