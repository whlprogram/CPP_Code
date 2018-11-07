#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
//计算字符串的前缀函数
int* computePrefix(const char *p, int n){
	if(p == NULL || n <= 0)
        return NULL;
	int *pr = new int[n];
	memset(pr, -1, sizeof(int)*n);
	int k = -1;
	for(int i  = 1; i < n; i++){
		while(k > -1 && p[k+1] != p[i])
            k = pr[k];
		if(p[k+1] == p[i])
            k = k+1;
        pr[i] = k;
	}//for
	return pr;
}//computePrefix

//返回两个字符串的前后重叠的最长子串的长度
int LCS(const char* p, int n, const char* s, int m){
	if(p == NULL || n <= 0 || s == NULL || m <= 0)
        return 0;
	int *pr = computePrefix(s, m);
	int k = -1;
	for(int i = 0; i < n; i++){
		while(k > -1 && s[k+1] != p[i])
            k = pr[k];
		if(s[k+1] == p[i])
            k = k+1;
		if(i != n-1 && k == m-1)
            k = pr[m-1];
	}
	delete[] pr;
	return k+1;
}//LCS

int main()
{
    string str;
    getline(cin , str);
    if(str == ""){
        return 0;
    }
    string str1, str2;
    int pos = str.find(' ', 0);//返回首次匹配的,下标
    str1 = str.substr(0, pos);//截取从字符串str中第0位开始的长度为pos的字符串
    int i;
    for(i=pos; i<str.size(); i++){
        if(str[i] != ' '){
            break;
        }
    }



    str2 = str.substr(i, str.size()-1-i);
    int lenTemp1 = LCS(str1.c_str(), str1.size(), str2.c_str(), str2.size());
    int lenTemp2 = LCS(str2.c_str(), str2.size(), str1.c_str(), str1.size());
    cout << lenTemp1 << " " << lenTemp2 << endl;
    int res = (lenTemp1>lenTemp2)?lenTemp1:lenTemp2;
    cout << res << endl;
    return 0;
}
//eeefffwqerwq  wqerwq
//6
//abcde cdefg
//3

