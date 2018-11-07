#include <iostream>

using namespace std;

int main()
{
    int n, MIN = 10001, sum=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp < MIN)
            MIN = temp;
        sum += temp;
    }
    cout << sum-MIN << endl;
    return 0;
}
