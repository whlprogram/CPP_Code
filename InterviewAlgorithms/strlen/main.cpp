#include <iostream>
#include <cstdio>
#include <assert.h>
#include <cstring>
using namespace std;
int i=0;
int strlen1(const char* str);
int strlen2(const char* str);
int strlen3(const char* str);
int main()
{
    char* str = nullptr;
    str = "Hello Word";
    printf("strlen(str)  = %d\n", strlen(str));
    printf("strlen1(str) = %d\n", strlen1(str));
    printf("strlen2(str) = %d\n", strlen2(str));
    printf("strlen3(str) = %d\n", strlen3(str));
    cout << "Hello world!" << endl;
    return 0;
}
int strlen1(const char* str) //不用临时变量 递归实现
{
    //printf("i=%d len=%d\n",i,str);
    //i++;
    if((str==nullptr) || *str=='\0')
        return 0;
    else
        return strlen1(str+1)+1;
}
int strlen2(const char* str) //不用临时变量
{
    assert(str != nullptr);
    /*printf("i=%d len=%d\n",i,str);
    i++;
    if(i == 11){
        printf("i=%d len=%d\n",i,str);
        return 0;
    }*/
    return *str ? (strlen2(++str)+1) : 0;//可以++str 写成str++则会出错
    //str++ 函数传值之后执行+1，而++str函数传值之前执行+1
}
int strlen3(const char* str)
{
    if(str == nullptr)
        return 0;
    int len = 0;
    for(;*str!='\0';str++)
        len++;
    return len;
}
