#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool Exception = true;//�ж��Ƿ��쳣
int strToIntCore(const char* str, bool minus){
    long long num = 0;
    while(*str != '\0'){
        if(*str >= '0' && *str<= '9'){
            int flag = minus ? 1 : -1;
            num = num * 10 + flag * (*str-'0');
            //����� ���� �����
            if( (minus && num>0x7FFFFFFF) || (!minus && num<(signed int)0x80000000) ){
                num = 0;
                break;
            }
            str++;
        }else{
            num = 0;
            break;
        }
    }//end while
    if(*str != '\0')//�����쳣��־λ
        Exception = false;
    return num;
}
int strToInt(const char* str){
    Exception = true;
    long long num = 0;
    if(str != NULL && *str != '\0'){//���ַ����ж�
        bool minus = true;//�������ж�
        if(*str == '+'){
            str++;
        }else if(*str == '-'){
            str++;
            minus = false;
        }
        if(*str != '\0'){
            num = strToIntCore(str, minus);
        }
    }
    return int(num);//ǿ��ת��Ϊint
}

int main()
{
    char str[10];
    gets(str);
    int res = strToInt(str);
    if(Exception)
        cout << res << endl;
    else
        cout << "��������" << endl;
    return 0;
}

