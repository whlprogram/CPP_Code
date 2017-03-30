#include <iostream>

using namespace std;

void fun1(int b)
{
    b = 1;
}
void fun2(int &b)
{
    b = 2;
}
void fun3(int *b)
{
    *b = 3;
}
int main()
{
    int a = 0;
    fun1(a);
    cout << "调用fun1后，a的值为：" << a << endl;//0  传值
    fun2(a);
    cout << "调用fun2后，a的值为：" << a << endl;//2  引用
    fun3(&a);
    cout << "调用fun3后，a的值为：" << a << endl;//3  传地址   相当于引用
    return 0;
}

/*
void swap1(int &a,int &b)
 {
     int t;
     t = a;
     a = b;
     b = t;
 }
 int main()
{
    int x = 5;
    int y = 10;
    cout << x << " " << y << endl;
    swap1(x, y);
    cout << x << " " << y << endl;//  结果是10，5
    return 0;
}
*/
/*
void swap1(int a,int b)
 {
     int t;
     t = a;
     a = b;
     b = t;
 }
 int main()
{
    int x = 5;
    int y = 10;
    cout << x << " " << y << endl;
    swap1(x, y);
    cout << x << " " << y << endl;// 结果是5，10，不是 引用，x和y的值压根就没有变化
    return 0;
}
*/
/*
void swap1(int &a,int b)
 {
     int t;
     t = a;
     a = b;
     b = t;
 }
 int main()
{
    int x = 5;
    int y = 10;
    cout << x << " " << y << endl;
    swap1(x, y);
    cout << x << " " << y << endl;// 10，10
    return 0;
}
*/
