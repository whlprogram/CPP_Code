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
    int temp = 2*k-1;//�ϰ벿�������ַ���Ŀո����
    //���Y���ϰ벿��
    for(int i=0; i<k; i++){
        for(int j=0; j<i; j++)//���ǰ��ո�
            printf(" ");
        printf("%c", str[2*i]);
        for(int q=0; q<temp; q++){//����м�ո�
            printf(" ");
        }
        temp -= 2;
        printf("%c\n", str[2*i+1]);
    }
    //���Y���°벿��
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
