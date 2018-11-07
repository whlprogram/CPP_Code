#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n <= 5){
        cout << 1 << endl;
        return 0;
    }
    int res = n/5;
    if(n%5 != 0)
        res++;
    cout << res << endl;
    return 0;
}
