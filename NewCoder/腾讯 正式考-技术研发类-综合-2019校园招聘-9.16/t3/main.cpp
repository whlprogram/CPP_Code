#include <bits/stdc++.h>

using namespace std;
int n;
bool foo(vector<int>& arr) {
    for(int i = 1; i < 80; ++i){
        if((arr[0]*i) % arr[1] != arr[2])
            continue;
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    vector<vector<int>> arr(n);
    int temp;
    for(int i=0; i<n; ++i){
        for(int j=0; j<3; ++j){
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
    for(int i=0; i<n; ++i){
        if(foo(arr[i]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
