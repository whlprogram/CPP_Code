#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//memcpy函数是内存拷贝函数，用于将一段内存空间数据拷贝到另一段内存空间中
//但是它和memmove函数不同的是，它对内存空间有要求的,要求不能重叠，否则发生结果不可预测
//dest和src所指向的内存空间不能重叠，否则的数据是错误的
//以下代码实现memcpy并做优化

//将src(源指针)的size个字符copy到dst(目的指针)处
void* memcpy(void* dst, const void* src, size_t size){
    assert((dst != NULL) && (src != NULL) && (size >= 0));//判断是否为空或者num是否小于等于0

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
//优化   按照int(4字节)分块copy  剩余不够一块(4字节)的按照单字节拷贝
void* memcpy_int(void* dst, const void* src, size_t size){
    assert((dst != NULL) && (src != NULL) && (size >= 0));//空指针或者size小于等于0
    int block = size/sizeof(int);//按照4字节分块
    int slice = size%sizeof(int);//最终不够一块的按照单字节copy

    int* pdst = (int *)dst;
    const int* psrc = (const int *)src;

    if(dst>src && dst<src+size){//重合 从高地址往低地址拷贝
        //最终不够一块的按照单字节copy
        char* pdst_char = (char *)dst+size-1;
        const char* psrc_char = (const char *)src+size-1;
        while(slice--)
            *pdst_char-- = *psrc_char--;
        pdst = (int *)dst+block-1;
        psrc = (const int *)src+block-1;
        //按块copy
        while(block--)
            *pdst-- = *psrc--;
    }else{//从低地址往高地址拷贝
        //先按照4字节copy
        while(block--){
            *pdst++ = *psrc++;
        }
        char* pdst_char = (char *)pdst;
        const char* psrc_char = (const char *)psrc;
        //先把最终不够一块的按照单字节copy
        while(slice--)
            *pdst_char++ = *psrc_char++;
    }
    return dst;
}

int main()
{
    char buf[100] = "abcdefghijklmn";
    cout << buf << endl;
    //memcpy(buf, buf+2, 5);
    //memcpy(buf, buf+5, 2);
    //memcpy(buf+2, buf, 5);
    //memcpy_int(buf, buf+4, 7);
    memcpy_int(buf+4, buf, 7);
    //memcpy(buf+4, buf, 5);
    cout << buf << endl;
    cout << buf+2 << endl;
    return 0;
}
