#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
void* memcpy(void* dst, const void* src, size_t size){
    if(src==NULL || size<=0)
        return dst;
    char* pdst = (char*)dst;
    const char* psrc = (const char *)src;
    if(pdst>psrc && pdst<psrc+size){//�غ� �Ӹߵ�ַ���͵�ַ����
        pdst = pdst+size-1;
        psrc = psrc+size-1;
        while(size--)
            *pdst-- = *psrc--;
    }else{//�ӵ͵�ַ���ߵ�ַ����
        while(size--)//��ǰ���󿽱�
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
