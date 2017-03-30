//练习二、输入一个字符串，内有数字和非数字字符，如：a123x456…17906?302tab5867，
//将其中连续的数字作为一个整数，一次存放到一数组a中。
//例如：123存放在a[0]，456存放在a[1]……，统计共有多少个整数，并输出这些数
#include<iostream>
#include <stdio.h>
#include<ctype.h>
using namespace std;
int main() {
    int *a,i = 0, nCount = 0;
    char str[100]; // 输入字符串
    gets(str);
    for(i=0; str[i]!='\0'; i++) //遍历字符串
    {
            if(isdigit(str[i]) && !isdigit(str[i+1])) //isdigit()判断输入字符是否为0~9的数字 所在函数库：ctype.h
            {
                nCount++; // 统计整数个数
            }
    }
    a = new int[nCount]; // 分配内存
    for(i=0; i<nCount; i++)
        {
            a[i] = 0;
            for(int j = 0; str[j]!='\0';j++)
            {
                if(isdigit(str[j]))//如果字符是为0~9的数字
                {
                    a[i] *= 10;
                    a[i] += (str[j] - '0');
                }
                else
                {
                    if(!isdigit(str[j-1]))
                    {
                        i--;
                    }
                    j++;
                    break;
                }
            }
        } // 结果输出
        cout<<"整数个数: "<<nCount<<endl;
        for(i=0; i<nCount; i++)
        {
            cout<<a[i]<<" ";
        }
        delete []a;
        return 0;
}
