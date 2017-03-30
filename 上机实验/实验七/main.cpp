/*练习一、创建一个时间类Date，包括数据成员年、月、日
（1）利用构造函数完成初始化数据成员，保证年、月、日的值正确，如果月份超出正常范围，将月置为1；
    设置三个构造函数：三参构造、两参构造和无参构造
（2）数据成员均为私有成员通过get和set函数进行访问
（3）定义成员函数displayDate，实现输出，格式要求：月/日/年
（4）成员函数要求在类体内声明，类体外定义
*/
#include <iostream>

using namespace System;
using namespace std;

int main(array<System::String^>^args)
{
    date a(2016,5,4);
    date b(2015,18,4);
    a.displaydate();
    b.displaydate();

    cout << "Hello world!" << endl;
    return 0;
}
