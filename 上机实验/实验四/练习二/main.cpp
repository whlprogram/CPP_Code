//给出年、月、日，计算该日是该年的第几天
#include <iostream>

using namespace std;

int main()
{
    cout << "请输入年 月 日：" << endl;
    int a=0,b=0,c=0;
    cin >> a;
    cin >> b;
    cin >> c;
    int arr[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //判断是否是闰年
    if(a%4==0 && a%100!=0)
    {
        arr[1] = 29;
    }
    //判断天数
    int sum = 0;
    for(int i =0;i< b-1;i++)
    {
        sum += arr[i];
    }
    sum += c;
    cout << a << "/" << b << "/" << c << "是全年的第" << sum << "天"<< endl;
    return 0;
}
