#include <iostream>
using namespace std;
int Hash[1001] = {0};
int fun(int k, int a, int x, int b, int y){
    if(Hash[k] != 0)
        return Hash[k];
    if(k == a)
        Hash[k] =  x;
    if(k == b)
        Hash[k] =  y;
    if(x == 0)
        Hash[k] = fun(k-b,a,x,b,y-1);
    if(y == 0)
        Hash[k] = fun(k-a,a,x-1,b,y);
    if(x!=0 && y!=0)
        Hash[k] = fun(k-a,a,x-1,b,y)*fun(k-b,a,x,b,y-1);
    return Hash[k];
}
int main()
{
    int k;
    int a,x,b,y;
    cin >> k;
    cin >> a >> x >> b >> y;
    if(a<0 || x<0 || b<0 || y<0)
        return 0;
    if(k<a && k<b){
        cout << 0 << endl;
        return 0;
    }
    if(k<a && k>b){
        int res = 1;
        for(int i=0; i<k/b; i++){
            res *= y;
            y--;
        }
        cout << res << endl;
        return 0;
    }
    if(k>a && k<b){
        int res = 1;
        for(int i=0; i<k/a; i++){
            res *= x;
            x--;
        }
        cout << res << endl;
        return 0;
    }
    long long res = fun(k, a, x, b, y)%1000000007;
    cout << res << endl;
    return 0;
}
