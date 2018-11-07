#include <bits/stdc++.h>

//int vis[1000005];
using namespace std;
bool gcd(int a, int b){//最大公约数
	int temp;
	while(b > 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	if(a == 1)
		return true;
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	int res = 0;
    int maxLen = sqrt(n);
    for (int i=1; i<=maxLen; i++){
        for (int j=i+1; j<=maxLen; j++){
            int c = j*j + i*i;
            if (c > n)
                break;
            int a = j*j - i*i;
            int b = 2*i*j;
            if (gcd(a, b) && gcd(a, c) && gcd(b, c)){
                res++;
            }
        }
    }
    printf("%d\n", res);
	return 0;
}

