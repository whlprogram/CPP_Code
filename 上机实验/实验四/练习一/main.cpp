//��ϰһ����һ�����֣�Ҫ��ɾȥ����ĳ���ַ����������ֺ�Ҫɾ���ַ����ɼ������롣
//Ҫɾ���ַ����ַ���ʽ���루������a��ʾҪɾȥ���е�a�ַ���
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    cout << "�������ַ�����" << endl;
    char str[1000];
    gets(str);
    cout << "������ɾ���ַ���" << endl;
    char remove_str;
    cin >> remove_str;
    int str_lenth = strlen(str);
    for(int i=0;i<=str_lenth;i++)
    {
        if(str[i] == remove_str)
        {
            for(int j =i;j<str_lenth;j++)
            {
                str[j] = str[j+1];
            }
            str_lenth = str_lenth - 1;
        }
    }
    for(int a=0;a<str_lenth;a++)
        cout << str[a];
    return 0;
}
