//���ַ�������ظ��Ӵ� LeetCode ��3��
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <algorithm>
using namespace std;
int getLongestSubString(string s){
	int arr[256];   //�����д�ŵ���ÿһ���ַ����±�λ�ã�
	memset(arr, -1, sizeof(arr));
	int pre = 0;
	int maxLen = 0;  //pre������ų��ֲ��ظ��Ӵ����׵�ַ
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
