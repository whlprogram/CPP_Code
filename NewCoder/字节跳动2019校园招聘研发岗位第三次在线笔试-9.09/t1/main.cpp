//求字符串最大不重复子串 LeetCode 第3题
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <algorithm>
using namespace std;
int getLongestSubString(string s){
	int arr[256];   //数组中存放的是每一个字符的下标位置；
	memset(arr, -1, sizeof(arr));
	int pre = 0;
	int maxLen = 0;  //pre用来存放出现不重复子串的首地址
	int n = s.length();
	for (int i=0; i<n; i++){
		if (arr[s[i]] != -1){
			if (arr[s[i]] >= pre){
				pre = arr[s[i]] + 1;
			}
			arr[s[i]] = i;
		}
		else{
			arr[s[i]] = i;
		}
		maxLen = max(maxLen, i-pre+1);
	}
	return maxLen;
}

int main()
{
    string str;
    getline(cin, str);
    cout << getLongestSubString(str) << endl;
    return 0;
}
