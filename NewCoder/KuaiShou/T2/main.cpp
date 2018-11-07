#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int n;
        cin >> n;
        if(n%3 != 0)
            cout << "lucky" << endl;
        else
            cout << "don't be discouraged" << endl;
    }
    return 0;
}
