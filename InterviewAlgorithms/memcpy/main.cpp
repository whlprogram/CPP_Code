#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//memcpy�������ڴ濽�����������ڽ�һ���ڴ�ռ����ݿ�������һ���ڴ�ռ���
//��������memmove������ͬ���ǣ������ڴ�ռ���Ҫ���,Ҫ�����ص����������������Ԥ��
//dest��src��ָ����ڴ�ռ䲻���ص�������������Ǵ����
//���´���ʵ��memcpy�����Ż�

//��src(Դָ��)��size���ַ�copy��dst(Ŀ��ָ��)��
void* memcpy(void* dst, const void* src, size_t size){
    assert((dst != NULL) && (src != NULL) && (size >= 0));//�ж��Ƿ�Ϊ�ջ���num�Ƿ�С�ڵ���0

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
//�Ż�   ����int(4�ֽ�)�ֿ�copy  ʣ�಻��һ��(4�ֽ�)�İ��յ��ֽڿ���
void* memcpy_int(void* dst, const void* src, size_t size){
    assert((dst != NULL) && (src != NULL) && (size >= 0));//��ָ�����sizeС�ڵ���0
    int block = size/sizeof(int);//����4�ֽڷֿ�
    int slice = size%sizeof(int);//���ղ���һ��İ��յ��ֽ�copy

    int* pdst = (int *)dst;
    const int* psrc = (const int *)src;

    if(dst>src && dst<src+size){//�غ� �Ӹߵ�ַ���͵�ַ����
        //���ղ���һ��İ��յ��ֽ�copy
        char* pdst_char = (char *)dst+size-1;
        const char* psrc_char = (const char *)src+size-1;
        while(slice--)
            *pdst_char-- = *psrc_char--;
        pdst = (int *)dst+block-1;
        psrc = (const int *)src+block-1;
        //����copy
        while(block--)
            *pdst-- = *psrc--;
    }else{//�ӵ͵�ַ���ߵ�ַ����
        //�Ȱ���4�ֽ�copy
        while(block--){
            *pdst++ = *psrc++;
        }
        char* pdst_char = (char *)pdst;
        const char* psrc_char = (const char *)psrc;
        //�Ȱ����ղ���һ��İ��յ��ֽ�copy
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
