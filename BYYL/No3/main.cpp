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
            num++;//��������+1
            if(MAP[temp] == 0){
                res++;//��ͬ��������+1
                MAP[temp]++;
            }
            temp = "";
            continue;
        }
        temp += s[i];
    }
    cout << "�ַ���s��" << num << "��Ӣ�ﵥ��," << res << "����ͬ��Ӣ�ﵥ��" << endl;
    return 0;
}
