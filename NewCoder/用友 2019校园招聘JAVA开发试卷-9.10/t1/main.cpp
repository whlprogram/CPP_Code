#include<bits/stdc++.h>
using namespace std;
vector<string> res;
int cmp(string a,string b){
	return a<b;
}
vector<string> result[100];
void print(int strLen,int pos){
	if(result[strLen].size() != 0){
        int len = result[strLen].size();
        for(int i=0; i<len; i++){
            string stemp = result[strLen][i].substr(0,strLen-2);
            if(result[strLen-2][pos] == stemp){//判断是否是子串
                for(int j=1; j<strLen/2; j++)//根据长度输出制表符
                    cout << "   ";
                cout << result[strLen][i] << endl;
                print(strLen+2, i);//递归输出子串
            }
        }
    }
}
int main(){
	string s;
	int n = 0;
	while(cin>>s && s!="-1"){
    //while(cin >> s){
		res.push_back(s);
		n++;
	}
	for(int i=0;i<n;i++){
		int k = res[i].length();
		if(k%2 != 0)
            continue;
		result[k].push_back(res[i]);
	}

	for(int i=2;;i+=2){
		if(result[i].size()==0)
            break;
		sort(result[i].begin(),result[i].end(),cmp);
	}
/*
	for(int i=2;;i+=2){
		if(result[i].size()==0)
            break;
		for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
	}
*/
	int len = result[2].size();
	for(int i=0; i<len; i++){
		cout << result[2][i] << endl;
		print(4, i);
	}
}
//01 0101 0301 03 030101 0201 02 0303 0401 033 03010101

