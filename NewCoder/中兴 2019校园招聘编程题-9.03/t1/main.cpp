#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
string userName, motherName;
int pwdLen;
vector<string> perm(vector<char> &sameChar, int start, int end
                    , vector<string> &res, int pwdLen){
    if(start == end){
        string str = "";
        bool flag = true;//判断是否按照字母顺序排列
        for(auto i=0; i<pwdLen; i++){
            str += sameChar[i];
            if(i>0 && sameChar[i]<sameChar[i-1]){
                flag = false;
                break;
            }
        }
        if(flag)
            res.push_back(str);
    }else{
        for(auto i=start; i<=end; i++){
            char temp = sameChar[start];
            sameChar[start] = sameChar[i];
            sameChar[i] = temp;

            perm(sameChar, start+1, end, res, pwdLen);
            //cout << *(sameChar.begin()+start
            //sameChar.erase(sameChar.begin()+start);

            temp = sameChar[start];
            sameChar[start] = sameChar[i];
            sameChar[i] = temp;

        }
    }
    return res;
}
vector<string> passwordList(string userName, string motherName, int pwdLen){
    vector<string> res;
    vector<char> sameChar;
    set<char> userNameSet, sameSet;
    for(auto i=0; i<userName.size(); i++){
        char ctemp = userName[i];
        if(ctemp>='A' && ctemp<='Z')
            ctemp = tolower(ctemp);
        userNameSet.insert(ctemp);
    }
    for(auto i=0; i<motherName.size(); i++){
        char ctemp = motherName[i];
        if(ctemp>='A' && ctemp<='Z')
            ctemp = tolower(ctemp);
        if(userNameSet.find(ctemp) != userNameSet.end())
            sameSet.insert(ctemp);//放入set中是排除userName和motherName中相同字符的重复值，比如两个a，留一个
    }
    for(auto it=sameSet.begin(); it!=sameSet.end(); it++)
        sameChar.push_back(*it);
    int lenSameChar = sameChar.size();
    if(lenSameChar < pwdLen)//相同字符数量小于给定密码长度，返回空密码
        return res;
    if(lenSameChar == pwdLen){//相同字符数量等于给定密码长度，只有一种情况
        string stemp = "";
        for(auto it=sameChar.begin(); it!=sameChar.end(); it++)
            stemp += *it;
        res.push_back(stemp);
        return res;
    }
    if(pwdLen == 1){//给定密码长度为1
        for(auto it=sameChar.begin(); it!=sameChar.end(); it++){
            string stemp;
            stemp += *it;
            res.push_back(stemp);
        }
        return res;
    }
    return perm(sameChar, 0, sameChar.size()-1, res, pwdLen);
}
int main()
{
    cin >> userName >> motherName >> pwdLen;
    vector<string> res = passwordList(userName, motherName, pwdLen);
    cout << res.size() << endl;
    for(auto i=0; i<res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
/*
RadheGupta
RADHIKA
3

ABCDRKSe
bckE
1
*/
