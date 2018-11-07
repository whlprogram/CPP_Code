/*
#include <cstdio>
#include <string.h>
void reverseString(char *str,unsigned int len) {
    char * p1,*p2;
    p1=p2=str;
    p2+=len-1;
    while(p1<p2) {
        *(p2+1)=*p1;
        *p1=*p2;
        p1++,p2--;
    }
    int half = len/2;
    for(int i=1;i<=half;i++) {
            *(p2+i)=*(p2+(i+1));
    }
    *(p2+(half+1))='\0';
    return ;
}
void reverseString2(char *str,unsigned int len) {
    char * p1,*p2;
    p1=p2=str;
    p2+=len-1;
    while(p1<p2) {
        *p2^=*p1;
        *p1^=*p2;
        *p2^=*p1;
        p1++,p2--;
    }
    return ;
}
int main() {
        static char test[]="reverse";
        static char test1[]="engine";
        static char test2[]="algorithm";
        printf("%s\r\n",test);
        reverseString2(test,strlen(test));
        printf("%s\r\n",test);
        printf("%s\r\n",test1);
        reverseString2(test1,strlen(test1));
        printf("%s\r\n",test1);
        printf("%s\r\n",test2);
        reverseString2(test2,strlen(test2));
        printf("%s\r\n",test2);
        return 0;
}
*/
#include <stdio.h>
#include <string.h>

/* memcpy������ʵ��*/
void myMemcpy(void *dest, const void *src, size_t count)
{
    char *pDest = (char *)dest;
    char *pSrc = (char *)src;
    /* Ŀ�ĵ�ַ��Դ��ַ�ص�����Դ��ַ��ĩβ����ʼ���� */
    if(pDest > pSrc && pDest < pSrc+count){
        for(pDest += (count-1), pSrc += (count-1); count != 0; count--){
            *pDest--= *pSrc--;
        }
    }else{
        /* Ŀ�ĵ�ַ��Դ��ַ���ص�����Դ��ַ�Ŀ�ʼ���򿽱� */
        while(count--){
            *pDest++ = *pSrc++;
        }
    }
};

/* ������ʱ��������ת�ַ���a[begin...end] */
void stringReverse(char a[], int begin, int end)
{
    for(; begin < end; begin++, end--){
        a[begin] ^= a[end];
        a[end] ^= a[begin];
        a[begin] ^= a[end];
    }
}

/* �Ե���Ϊ��λ��ת�ַ��� */
void stringReverseOnWord(char a[])
{
    char *begin = a;
    char *end = a;
    int len = strlen(a);
    int flag = 0;

    /* ���ڿ��ַ����Լ�ֻ��һ���ַ����ַ��������κδ��� */
    if(*a == '\0' || *(a+1) == '\0') {
        return;
    }
    /* ɾ�����ʼ��ظ��Ŀո�ֻ����һ�� */
    for(; *begin != '\0'; begin++){
        if(*begin == ' '){
            flag = 1;
            end = begin+1;
            while(*end == ' '){
                end++;
            }
            myMemcpy(begin+1, end, len-(end-1-a)); /* ��ȫ�����ÿ⺯�����棬�˴�ֻ�Ǹ�ϰ��memcpy��ʵ�� */
        }
    }
   /* endָ���ַ�����β��'\0'���ڴ����ַ���ǰ����Ҫ��endָ�����һ����'\0'�� */
    end = begin;
    --end;
    /* ɾ���ַ���ĩβ�Ŀո� */
    while(*end == ' '){
        *end = '\0';
        end--;
    }

    /* �ַ�����ֹһ�����ʣ���Ҫ��ת */
    if(flag == 1){
        stringReverse(a, 0, end-a);
        /* ɾ���ַ���ĩβ�Ŀո� */
        while(*end == ' '){
            *end = '\0';
            end--;
        }
        for(begin = end =a; *end != '\0'; end++){
            if(*end == ' '){ /* beginָ�򵥴ʵĵ�һ���ַ���(end-1)ָ��õ��ʵ�ĩβ */
                stringReverse(begin, 0, end-1-begin);
                begin = end+1;
            }
        }
        /* ���һ�����ʵĴ��� */
        if(*end == '\0' && end-begin > 1){
            stringReverse(begin, 0, end-begin-1);
        }
    }

}

int main()
{
    char a[] = "All-in-one";
    char b[] = " hello             I            will be with you";

    printf("%s\n", a);
    stringReverseOnWord(a);
    printf("%s\n", a);

    printf("%s\n", b);
    stringReverseOnWord(b);
    printf("%s\n", b);

    return 0;
}
