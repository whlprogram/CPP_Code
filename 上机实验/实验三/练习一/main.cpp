#include <iostream>
//#include <STDARG.H>
/*
    编写函数验证哥德巴赫猜想：一个不小6的偶数可以表示为两个素数之和，如6=3+3,8=3+5,10=3+7,…..，
    在主函数中输入一个不小于6的偶数n，然后调用函数gotbaha，在gotbaha函数中调用prime函数，
    prime函数的作用是判别一个数是否为素数。
*/
using namespace std;
bool prime(int);
void gotbaha(int);
int main()
{
    int a = 0;
    cout << "请输入一个大于（等于）6的偶数：";
    cin >> a;
    while (a%2 != 0 || a < 6)
    {
        cout << "请重新输入：";
        cin >> a;
    }
    gotbaha(a);
    return 0;
}
bool prime(int num)//判断是否为素数
{
    for(int i=2;i<num;i++)
    {
        if(num % i == 0)
        {
            return false;//0
            break;
        }
    }
    return true;//1
}
void gotbaha(int num)//找出符合条件的两个素数
{
    for(int subtrahend_1=3; subtrahend_1 <= num/2; subtrahend_1++)
    {
        if(prime(subtrahend_1) == 1)//第一个素数的判断，引用prime()方法
        {
           int subtrahend_2 = num - subtrahend_1;
           if(prime(subtrahend_2) == 1)//第二个素数的判断，引用prime()方法
           {
                cout << num << "=" << subtrahend_1 << "+" << subtrahend_2 << endl;
           }
        }
    }
}
