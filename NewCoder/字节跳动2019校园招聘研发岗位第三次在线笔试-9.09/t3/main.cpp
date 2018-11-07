//LeetCode 第93题
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isValidIP(string str){
	if (str.size()>1 && str[0]=='0')
		return false;
	int res = atoi(str.c_str());
	return res<=255 && res>=0;
}

void DFS(string str, string half, int &res, int count){
	if (count==3 && isValidIP(str)){
		res++;
		return;
	}
	//可以取1-3个字符
	for (int i=1; i<=3&&i<str.size(); ++i){//特别需要注意i<s.size(){
		string stemp = str.substr(0, i);
		if(isValidIP(stemp))
			DFS(str.substr(i), half+stemp+".", res, count+1);
	}
}

int main(){
	string str;
	getline(cin, str);
	if (str.size()<4 || str.size()>12)
        return 0;
    int res = 0;//如果需要统计所有IP，只需要将res换成数组，在res++的地方进行push_back即可
    DFS(str, "", res, 0);
    cout << res << endl;
	return 0;
}

