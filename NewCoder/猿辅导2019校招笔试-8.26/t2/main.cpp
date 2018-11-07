#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int N;
int main()
{
    scanf("%d\n", &N);
    int k = N/3;
    string str;
    getline(cin, str);
    int temp = 2*k-1;//上半部分两个字符间的空格个数
    //输出Y的上半部分
    for(int i=0; i<k; i++){
        for(int j=0; j<i; j++)//输出前面空格
            printf(" ");
        printf("%c", str[2*i]);
        for(int q=0; q<temp; q++){//输出中间空格
            printf(" ");
        }
        temp -= 2;
        printf("%c\n", str[2*i+1]);
    }
    //输出Y的下半部分
    for(int i=0; i<=k; i++){
        for(int j=0; j<k; j++)
            printf(" ");
        printf("%c\n", str[2*k+i]);
    }
    return 0;
}
/*
4
a3f/

7
abcdefg

10
iiiiiiiiii
*/
