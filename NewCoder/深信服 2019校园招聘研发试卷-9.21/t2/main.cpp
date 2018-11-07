#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        float a1, b1, v1, a2, b2, v2, x, y;
        cin >> a1 >> b1 >> v1 >> a2 >> b2 >> v2;
        if(a1+b1 == v1 && a2+b2 == v2){
            cout << 1 << " " << 1 << endl;
            continue;
        }
        x = (v1-b1/b2*v2)/(a1-b1/b2*a2);
        y = (v2-a2*x)/b2;
        if(x >= 0 && x <= 1000000000 && y >= 0 && y <= 1000000000
           && x-(int)x == 0 && y-(int)y == 0){
            cout << x << " " << y << endl;
            continue;
        }
        cout << "UNKNOWN" << endl;
        //cout << x << " " << y << endl;
    }
    return 0;
}
/*
3
1 2 3 4 5 9
1 2 3 4 5 6
1 2 3 3 6 9

1 1
UNKNOWN
1 1

1 1
UNKNOWN
UNKNOWN
*/
