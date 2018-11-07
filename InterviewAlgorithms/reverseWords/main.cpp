//说反话
//给一段字符串，由单词和空格组成，翻转单词的顺序
//输入 Wuhan Hubei to Welcom
//输出 Welcom to Hubei Wuhan

//方法一 指针
/*
#include <iostream>
#include <string>
using namespace std;
void string_inv(char str[], unsigned int len);
int main()
{
    string s;
    getline(cin, s);
    char str[s.size()];
    for(int i=0; i<s.size(); i++)
        str[i] = s[i];
    unsigned int len = s.size()-1;//最右下标
    string_inv(str, len);
    return 0;
}
void string_inv(char str[], unsigned int len){//指针方式
    char *b = str+len;
    char *e = str+len;
    for (;b != str;b=e)
    {
        while(*(--e)!=' '&& e != str);
        for (char *temp = (str == e)?e:e+1;temp < b+1;temp++)
        {
            cout << *temp ;
        }
        if(e-- == str)
            break;
        cout << ' ';
    }

}
*/

//方法二 下标
#include <iostream>
#include <string>
using namespace std;
void reverseStrWords(string str, int len);

int main()
{
    //Wuhan Hubei to Welcom
    string str;
    getline(cin, str);
    int len = str.size()-1;
    reverseStrWords(str, len);
}
void reverseStrWords(string str, int len)
{
    int b = len;
    int e = len;
    for(; b!=0; b=e)
    {
        while(e!=0 && str[e]!=' ')//从后往前寻找最后一个单词的开头下标
        {
            e--;
        }
        //cout << e << ": " << str[e] << endl;
        for(int temp = (e==0?0:(e+1)); temp<=b; temp++)
        {
            cout << str[temp];
        }
        if(e == 0)
            break;
        cout << str[e];
        e--;
    }
}
