#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main()
{
    string str;
    cin >> str;
    vector<int> vec;
    for(int i=0; i<str.size(); i++){
        int temp = str[i]-'a';
        arr[temp]++;
    }
    int minNum = 0;
    //找出最少的字符  一定要排除字符数量为0的情况
    for(int i=0; i<26; i++){
        if(arr[i] != 0){
            minNum = i;
            break;
        }
    }
    for(int i=0; i<26; i++){
        if(arr[i] < arr[minNum] && arr[i] != 0)
            minNum = i;
    }
    //将数量最少的字符对应的数字全部加入vec
    for(int i=0; i<26; i++){
        if(arr[i] == arr[minNum])
            vec.push_back(i);
    }
    for(int i=0; i<str.size(); i++){
        bool flag = true;
        int temp = str[i]-'a';
        for(int j=0; j<vec.size(); j++){//判断字符是否主要删除
            if(vec[j] == temp){
                flag = false;
                break;
            }

        }
        if(flag)
            cout << str[i];
    }
    return 0;
}
