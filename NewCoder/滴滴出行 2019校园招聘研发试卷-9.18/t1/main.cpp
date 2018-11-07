#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<char> d1 = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v'};
set<char> d2 = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'b', 'n', 'm'};
bool cmp(pair<string,int> a, pair<string,int> b){
	return a.second < b.second;
}
int mins(int a,int b,int c){
	if(a > b)
		a = b;
	if(a > c)
		a = c;
	return a;
}
void fun(string s, pair<string,int> &a){
	string temp = a.first;
	vector<vector<int>> dp;
	for(int i=0; i<s.size(); i++){
		vector<int> te(temp.size(), 0);
		dp.push_back(te);
	}
	for(int i=0; i<s.size(); i++){
		dp[i][0] = 3*i;
	}
	for(int i=0; i<temp.size(); i++){
		dp[0][i] = 3*i;
	}
	for(int i=1; i<s.size(); i++){
		for(int j=1; j<temp.size(); j++){
			char a = s[i];
			char b = temp[j];
			int num = dp[i-1][j-1];
			if(a == b)
				num = num;
			else if((d1.count(a) && d1.count(b)) || (d2.count(a) && d2.count(b)))
				num += 1;
			else
				num += 2;
			dp[i][j] = mins(num, dp[i-1][j]+3, dp[i][j-1]+3);
		}
	}
	a.second = dp[s.size()-1][temp.size()-1];
}
int main()
{
	string s;
	getline(cin, s);
	vector<pair<string, int>> data;
	string st = "";
	for(int i=0; i<s.size(); i++){
		if(s[i] == ' '){
			data.push_back(make_pair(st, INT_MAX));
			st = "";
		}else{
		    st += s[i];
		}
	}
	data.push_back(make_pair(st, INT_MAX));

	string sss = data[0].first;//保存目标字符转
	data.erase(data.begin());//从数组中去除目标字符转
	for(int i=0; i<data.size(); i++){
		fun(sss, data[i]);
	}
	sort(data.begin(), data.end(), cmp);
	for(int i=0;i<=1;i++){
		cout << data[i].first << " ";
	}
	cout << data[2].first;
	return 0;
}
/*
输入：
slep slap sleep step shoe shop snap slep
输出：
slep slap step

输入：
slep slap silep sleep stoep shole shoop solep slep
输出：
slep slap silep
*/
