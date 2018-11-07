#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int pos = 0;
    for(int i=0; i<str1.size(); i++){
        if(str1[i] == '*'){
            pos = i;
        }
    }
    for(int i=0; i<str2.size(); i++){
        if(str1[pos+1] == str2[i]){
            pos = i;
            break;
        }
    }
    int len = str2.size();
    for(int i=0; i<=pos; i++){
        cout << i << " " << len-- << endl;
    }
    return 0;
}
