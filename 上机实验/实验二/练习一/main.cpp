/*
练习一、给一个不多于5位的正整数，按照要求输出：
（1）输出正整数的位数
（2）输出正整数的每一位数字及所在位标示（如：十位数8）
（3）逆序输出各位数字
*/
#include <iostream>
using namespace std;

int main()
{
    int x = 0; //默认值为0
    cout << "请输入正整数（0-99999）:";
    cin >> x;
    //如果输入不正确处理办法
    if (x <= 0)
        x = 1;
    else if (x > 99999)
        x = 99999;
    else
        x = int(x);
    int Y = x; //用Y储存x值
    //判断位数
    int weishu = 0;
    while (x > 0)
    {
       x = x / 10;
       weishu++;
    }
    cout <<  Y << "位数是:" << weishu <<endl;
    cout << "逐位输出: 万位：" << Y/10000 << ", 千位：" << Y/1000%10
         << ", 百位：" << Y/100%10 << ", 十位：" << Y/10%10 << ", 个位：" << Y%10 <<endl;

    //逆序输出
    int nixu = Y; //个位数逆序还是它本身
    if(weishu == 5)
        nixu = Y/10000 + Y/1000%10*10 + Y/100%10*100 + Y/10%10*1000 + Y%10*10000;
    else if (weishu == 4)
        nixu = Y/1000 + Y/100%10*10 + Y/10%10*100 + Y%10*1000;
    else if (weishu == 3)
        nixu = Y/100 + Y/10%10*10 + Y%10*100;
    else if (weishu == 2)
        nixu = Y/10 + Y%10*10;

    cout << "逆序输出: " << nixu <<endl;
    return 0;
}
