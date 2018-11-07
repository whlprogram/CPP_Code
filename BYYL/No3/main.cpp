#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    map<string, int> MAP;
    int num = 0, res = 0;
    string temp = "";
    for(int i=0; i<s.size(); i++){
        if(s[i]==' ' || s[i]=='.' || s[i]==','|| s[i]=='?' || s[i]=='!'){
            num++;//单词数量+1
            if(MAP[temp] == 0){
                res++;//不同单词数量+1
                MAP[temp]++;
            }
            temp = "";
            continue;
        }
        temp += s[i];
    }
    cout << "字符串s有" << num << "个英语单词," << res << "个不同的英语单词" << endl;
    return 0;
}
