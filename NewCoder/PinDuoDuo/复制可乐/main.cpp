#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n<1 || n>1000000000)
        return 0;
    string arr[4] = {"Alice", "Bob", "Cathy", "Dave"};
    int res = 0;
    for(int i=1; i<=30; i++){
        if(n > (pow(2, i+2)-4))
            res = i;
        else if(n == (pow(2, i+2)-4)){
            cout << arr[3] << endl;
            return 0;
        }
        else
            break;
    }
    cout << res << endl;
    int x = n - (pow(2, res+2)-4);
    cout << "x=" << x << endl;
    ++res;
    int y = pow(2, res+1)/4;
    int a = x%y == 0 ? x/y-1 : x/y;
    cout << arr[a] << endl;
    return 0;
}
