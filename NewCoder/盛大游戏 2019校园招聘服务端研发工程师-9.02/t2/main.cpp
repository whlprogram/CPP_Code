/*
每次从字符串首位取较小字符输出
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str="", res="";
    cin >> str;
    if(str == "")
        return 0;
    if(str.size() == 1)
        cout << str << endl;
    int left = 0;
    int right = str.size()-1;
    while(left != right){
        if(str[left] >= str[right]){
            res += str[right];
            --right;
        }else{
            res += str[left];
            ++left;
        }
    }
    res += str[left];
    cout << res << endl;
    return 0;
}
