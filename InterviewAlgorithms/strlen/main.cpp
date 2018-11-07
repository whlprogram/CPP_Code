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
int strlen1(const char* str) //������ʱ���� �ݹ�ʵ��
{
    //printf("i=%d len=%d\n",i,str);
    //i++;
    if((str==nullptr) || *str=='\0')
        return 0;
    else
        return strlen1(str+1)+1;
}
int strlen2(const char* str) //������ʱ����
{
    assert(str != nullptr);
    /*printf("i=%d len=%d\n",i,str);
    i++;
    if(i == 11){
        printf("i=%d len=%d\n",i,str);
        return 0;
    }*/
    return *str ? (strlen2(++str)+1) : 0;//����++str д��str++������
    //str++ ������ֵ֮��ִ��+1����++str������ֵ֮ǰִ��+1
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
