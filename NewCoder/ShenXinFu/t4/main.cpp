/*
#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, string>> fun(const string& str)
{
	vector<string> subs;
	vector<pair<int, string>> res;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		subs.push_back(str.substr(i));
	}
	int length;
	string sub;
	//i为子串的长度
	for (int i = 1; i <= len/2; i++)
	{
		for (int j = 0; 2*i + j <= len; j++)
		{

			if (subs[j + i].substr(0, i) == subs[j].substr(0, i))
			{
				length = 2 * i;
				sub = subs[j].substr(0, i) + subs[j].substr(0, i);
				res.clear();
				res.push_back(make_pair(length, sub));
			}
			//res.push_back(make_pair(length, sub));
		}
	}
	return res;
}

int main()
{
	string str;
	vector<pair<int, string>> res;
	while (cin >> str)
	{
		res = fun(str);
		for (auto it = res.begin(); it != res.end(); it++)
		{
			//cout << it->second << ":" << it->first << endl;
			cout << it->first << endl;
		}
	}
	return 0;
}
*/

//ask not what your country  can do for you ,but what you can do for your  country
/*给定出一个字符串，输出最长的重复子字符串*/
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
const int MaxCharNum = 5000000;

bool StrCmp(char* str1,char* str2);
void GenSuffixArray(char* str,char* suffixStr[]);
int ComStrLen(char* str1,char* str2);
void GenMaxReStr(char* str);
int main()
{
    char str[MaxCharNum];
    cin.getline(str,MaxCharNum);//遇到回车结束
    GenMaxReStr(str);
    system("pause");
    return 1;
}
void GenMaxReStr(char* str)
{
    int len = strlen(str);
    int comReStrLen = 0;
    int maxLoc = 0;
    int maxLen = 0;
    char* suffixStr[MaxCharNum];
    GenSuffixArray(str,suffixStr);//产生后缀数组
    //对后缀数组进行排序
    sort(suffixStr,suffixStr+len,StrCmp);
    //统计相邻单词中相同的字符数，并输出结果
    for(int i = 0;i < len-1;i++ )
    {
        comReStrLen = ComStrLen(suffixStr[i],suffixStr[i+1]);
        if(comReStrLen > maxLen)
        {
            maxLoc = i;
            maxLen = comReStrLen;
        }
    }
    //输出结果
    for(int i = 0;i < maxLen;i++)
    {
        cout<<suffixStr[maxLoc][i];
    }
    cout<<endl;
}
/*为字符串产生其后缀数组，并存放到数组suffixStr中*/
void GenSuffixArray(char* str,char* suffixStr[])
{
    int len = strlen(str);
    for(int i = 0;i < len;i++)
    {
        suffixStr[i] = &str[i];
    }
}
    /*返回str1和str2的共同前缀的长度*/
int ComStrLen(char* str1,char* str2)
{
    int comLen = 0;
    while(*str1 && *str2)
    {
        if (*str1 == *str2)
        {
            comLen++;
        }
        str1++;
        str2++;
    }
    return comLen;
}
//字符串升序排序
bool StrCmp(char* str1,char* str2)
{
    if(strcmp(str1,str2) >=0 )
    {
        return false;
    }
    return true;
}
