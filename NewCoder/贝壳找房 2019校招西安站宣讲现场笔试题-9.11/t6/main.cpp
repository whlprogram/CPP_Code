#include <iostream>

using namespace std;
int getLast4Num(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    int result = 0;
    int lessOf1 = 0;
    int lessOf2 = 1;
    for(int i=2; i<=n; i++){
        result = lessOf1 + lessOf2;
        if(result >= 10000)
            result = result%10000;
        lessOf1 = lessOf2;
        lessOf2 = result;
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    cout << getLast4Num(n) << endl;
    return 0;
}
