//选择题中的程序
/*
#include <iostream>

using namespace std;
class Base
{
public:
    virtual void f(){cout << "f0+";}
    void g(){cout << "g0+";}
};
class Derived : public Base
{
public:
    void f(){cout << "f+";}
    void g(){cout << "g+";}
};
int main()
{
    Derived d;
    Base* p = &d;
    p->f();//f+
    p->g();//g0+
    d.f();//f+
    d.g();//g+
    return 0;
}
*/
/*
#include <stdio.h>
int f(int i);
int main()
{
    int m=1000, n;
    n = f(f(f(m)));
    printf("%d\n", n);//以整形输出整数
    printf("%o\n", n);//以八进制数形式输出整数
    return 0;
}
int f(int i)
{
    static float j = 2;
    j++;
    return i/j;
}
*/
#include <stdio.h>
int main()
{
    char aa[][3] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char (*p)[3] = aa;
    //p是指向数组（元素个数为3）的指针
    p++;

    printf("%c\n", **p);
    return 0;

}
