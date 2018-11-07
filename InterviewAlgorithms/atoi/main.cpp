#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool Exception = true;//判断是否异常
int strToIntCore(const char* str, bool minus){
    long long num = 0;
    while(*str != '\0'){
        if(*str >= '0' && *str<= '9'){
            int flag = minus ? 1 : -1;
            num = num * 10 + flag * (*str-'0');
            //正溢出 或者 负溢出
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
    if(*str != '\0')//更新异常标志位
        Exception = false;
    return num;
}
int strToInt(const char* str){
    Exception = true;
    long long num = 0;
    if(str != NULL && *str != '\0'){//空字符串判断
        bool minus = true;//正负号判断
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
    return int(num);//强制转换为int
}

int main()
{
    char str[10];
    gets(str);
    int res = strToInt(str);
    if(Exception)
        cout << res << endl;
    else
        cout << "输入有误" << endl;
    return 0;
}

