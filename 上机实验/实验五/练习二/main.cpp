//��ϰ��������һ���ַ������������ֺͷ������ַ����磺a123x456��17906?302tab5867��
//������������������Ϊһ��������һ�δ�ŵ�һ����a�С�
//���磺123�����a[0]��456�����a[1]������ͳ�ƹ��ж��ٸ��������������Щ��
#include<iostream>
#include <stdio.h>
#include<ctype.h>
using namespace std;
int main() {
    int *a,i = 0, nCount = 0;
    char str[100]; // �����ַ���
    gets(str);
    for(i=0; str[i]!='\0'; i++) //�����ַ���
    {
            if(isdigit(str[i]) && !isdigit(str[i+1])) //isdigit()�ж������ַ��Ƿ�Ϊ0~9������ ���ں����⣺ctype.h
            {
                nCount++; // ͳ����������
            }
    }
    a = new int[nCount]; // �����ڴ�
    for(i=0; i<nCount; i++)
        {
            a[i] = 0;
            for(int j = 0; str[j]!='\0';j++)
            {
                if(isdigit(str[j]))//����ַ���Ϊ0~9������
                {
                    a[i] *= 10;
                    a[i] += (str[j] - '0');
                }
                else
                {
                    if(!isdigit(str[j-1]))
                    {
                        i--;
                    }
                    j++;
                    break;
                }
            }
        } // ������
        cout<<"��������: "<<nCount<<endl;
        for(i=0; i<nCount; i++)
        {
            cout<<a[i]<<" ";
        }
        delete []a;
        return 0;
}
