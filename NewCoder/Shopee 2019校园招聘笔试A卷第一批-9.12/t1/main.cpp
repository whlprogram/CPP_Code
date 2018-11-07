#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    map<char, int> myMap;
    char stemp;
    for(int i=0; i<str.size(); i++){
        stemp = tolower(str[i]);
        myMap[stemp] += 1;
    }
    for(auto it=myMap.begin(); it!=myMap.end(); it++){
        cout << it->first << ":" << it->second << endl;
    }
    return 0;
}
