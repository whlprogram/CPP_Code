#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}
int main()
{
    long long t;
    cin >> t;
    while(t--){
        long long x,a,c,y,b,d;
        cin >> x >> a >> c >> y >> b >> d;
        long long time = 0;
        x -= b;
        y -= a;
        long long g = gcd(c, b);
        long long xCdTime = 0;
        long long yCdTime = 0;
        while(x>0 && y>0){
            xCdTime += g;
            yCdTime += g;
            if(xCdTime == c){
                y -= a;
                xCdTime = 0;
            }
            if(yCdTime == d){
                x -= b;
                yCdTime = 0;
            }
        }
        if(x<=0 && y<=0)
            cout << "TIE" << endl;
        else if(x <= 0 && y > 0)
            cout << "XIAOCHUN" << endl;
        else if(x > 0 && y <= 0)
            cout << "XIAOZHI" << endl;
    }
    return 0;
}
/*
4
1 2 3 4 5 6
128 39 20 109 100 92
1000 10 39 33 333 39
101 10 10 101 20 20

XIAOCHUN
XIAOZHI
TIE
TIE
*/
