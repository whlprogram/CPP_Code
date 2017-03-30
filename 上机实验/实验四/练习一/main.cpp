//练习一、有一行文字，要求删去其中某个字符。此行文字和要删的字符均由键盘输入。
//要删的字符以字符形式输入（如输入a表示要删去所有的a字符）
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    cout << "请输入字符串：" << endl;
    char str[1000];
    gets(str);
    cout << "请输入删除字符：" << endl;
    char remove_str;
    cin >> remove_str;
    int str_lenth = strlen(str);
    for(int i=0;i<=str_lenth;i++)
    {
        if(str[i] == remove_str)
        {
            for(int j =i;j<str_lenth;j++)
            {
                str[j] = str[j+1];
            }
            str_lenth = str_lenth - 1;
        }
    }
    for(int a=0;a<str_lenth;a++)
        cout << str[a];
    return 0;
}
