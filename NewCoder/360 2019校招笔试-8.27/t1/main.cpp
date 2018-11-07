#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int xmax=0, xmin=1e9, ymax=0, ymin=1e9, X_MAX=0, Y_MAX=0;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        if(x > xmax)
            xmax = x;
        if(y > ymax)
            ymax = y;
        if(x < xmin)
            xmin = x;
        if(y < ymin)
            ymin = y;
    }
    long res = max(xmax-xmin,ymax-ymin);
    cout << res*res << endl;
    return 0;
}
