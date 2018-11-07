#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
void* memcpy(void* dst, const void* src, size_t size){
    if(src==NULL || size<=0)
        return dst;
    char* pdst = (char*)dst;
    const char* psrc = (const char *)src;
    if(pdst>psrc && pdst<psrc+size){//重合 从高地址往低地址拷贝
        pdst = pdst+size-1;
        psrc = psrc+size-1;
        while(size--)
            *pdst-- = *psrc--;
    }else{//从低地址往高地址拷贝
        while(size--)//从前往后拷贝
            *pdst++ = *psrc++;
    }
    return dst;
}
int main()
{
    char src[1000];
    char dst[1000];
    scanf("%s", &src);
    memcpy(dst, src, 1000);
    printf("%s", dst);
    return 0;
}
