#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    string res = "";
    cin >> n;
    while(n != 0){
        if(n % 2 == 0){
            n = (n-2)/2;
            res = '3' + res;
        }else{
            n = (n-1)/2;
            res = '2' + res;
        }
    }
    cout << res << endl;
    return 0;
}
