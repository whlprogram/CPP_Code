#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;//(1<=n<=10^5)
    scanf("%d", &n);
    int temp1 = n;
    int temp2 = 0;
    while(n > 0){
        int a = n%10;
        n /= 10;
        temp2 = temp2*10 + a;
    }
    printf("%d", temp1+temp2);
    return 0;
}
