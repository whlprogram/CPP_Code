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

/* memcpy函数的实现*/
void myMemcpy(void *dest, const void *src, size_t count)
{
    char *pDest = (char *)dest;
    char *pSrc = (char *)src;
    /* 目的地址和源地址重叠，从源地址的末尾方向开始拷贝 */
    if(pDest > pSrc && pDest < pSrc+count){
        for(pDest += (count-1), pSrc += (count-1); count != 0; count--){
            *pDest--= *pSrc--;
        }
    }else{
        /* 目的地址和源地址不重叠，从源地址的开始方向拷贝 */
        while(count--){
            *pDest++ = *pSrc++;
        }
    }
};

/* 不用临时变量，翻转字符串a[begin...end] */
void stringReverse(char a[], int begin, int end)
{
    for(; begin < end; begin++, end--){
        a[begin] ^= a[end];
        a[end] ^= a[begin];
        a[begin] ^= a[end];
    }
}

/* 以单词为单位翻转字符串 */
void stringReverseOnWord(char a[])
{
    char *begin = a;
    char *end = a;
    int len = strlen(a);
    int flag = 0;

    /* 对于空字符串以及只有一个字符的字符串不做任何处理 */
    if(*a == '\0' || *(a+1) == '\0') {
        return;
    }
    /* 删除单词间重复的空格，只保留一个 */
    for(; *begin != '\0'; begin++){
        if(*begin == ' '){
            flag = 1;
            end = begin+1;
            while(*end == ' '){
                end++;
            }
            myMemcpy(begin+1, end, len-(end-1-a)); /* 完全可以用库函数代替，此处只是复习下memcpy的实现 */
        }
    }
   /* end指向字符串结尾处'\0'，在处理字符串前，还要将end指向最后一个非'\0'处 */
    end = begin;
    --end;
    /* 删除字符串末尾的空格 */
    while(*end == ' '){
        *end = '\0';
        end--;
    }

    /* 字符串不止一个单词，需要翻转 */
    if(flag == 1){
        stringReverse(a, 0, end-a);
        /* 删除字符串末尾的空格 */
        while(*end == ' '){
            *end = '\0';
            end--;
        }
        for(begin = end =a; *end != '\0'; end++){
            if(*end == ' '){ /* begin指向单词的第一个字符，(end-1)指向该单词的末尾 */
                stringReverse(begin, 0, end-1-begin);
                begin = end+1;
            }
        }
        /* 最后一个单词的处理 */
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
