#include <iostream>
#include <map>
using namespace std;

int main()
{
    int x;
    cin >> x;
    for(int i=0; i<x; i++){
        map<char, int> MAP;
        int n, k;
        cin >> n >> k;
        if(n==1 && k==1){
            cout << "false" << endl;
            continue;
        }
        for(int j=0; j<n; j++){
            for(int q=0; q<k; q++){
                char ctemp;
                cin >> ctemp;
                MAP[ctemp]++;
            }
        }
        bool flag = true;
        for(auto it=MAP.begin(); it!=MAP.end(); it++){
            if(it->second == 1){
                flag = false;
                cout << "true" << endl;
                break;
            }
        }
        if(flag)
            cout << "false" << endl;
    }
    return 0;
}
