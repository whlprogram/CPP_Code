#include<iostream>
#include<assert.h>
#include<bits/stdc++.h>
using namespace std;

typedef void(*Fun) ();   //定义一个函数指针类型
                         //Fun就是函数指针类型
class Base
{
    public:
        virtual void fun1()
        {
            cout << "Base::fun1()" << endl;
        }
        virtual void fun2()
        {
            cout << "Base::fun2()" << endl;
        }
    private:
        int d;
};

class Derive : public Base
{
    public:
        virtual void fun1()
        {
            cout << "Derive::fun1()" << endl;
        }
        virtual void fun3()
        {
            cout << "Derive::fun3()" << endl;
        }
        virtual void fun4()
        {
            cout << "Derive::fun4()" << endl;
        }
    private:
        int d;
};

class Child : public Base
{
    public:
        virtual void fun1()
        {
            cout << "Child::fun1()" << endl;
        }
        virtual void fun3()
        {
            cout << "Child::fun3()" << endl;
        }
        virtual void fun4()
        {
            cout << "Child::fun4()" << endl;
        }
    private:
        int d;
};
class GreadChild : public Child
{
    public:
        virtual void fun1()
        {
            cout << "GreadChild::fun1()" << endl;
        }
        virtual void fun3()
        {
            cout << "GreadChild::fun3()" << endl;
        }
        virtual void fun5()
        {
            cout << "GreadChild::fun5()" << endl;
        }
    private:
        int d;
};
//
void Print_Table(int* VTable)
{
    cout << "虚表地址 " << VTable << endl;
    for (int i = 0; VTable[i] != 0; i++)
    {
        printf("第%d个虚函数地址是ox%p->", i, VTable[i]);
        Fun f = (Fun)VTable[i];
        f();
    }
}
int main()
{
    Base b;
    Derive d;
    Child c;
    GreadChild g;
    /*
    Child *x = &g;
    x->fun1();

    Base *base = &g;
    base->fun1();
    */
    int* VTableB = *((int**)(&b));
    int* VTableD = *((int**)(&d));
    int* VTableC = *((int**)(&c));
    int* VTableG = *((int**)(&g));
    Print_Table(VTableB);
    Print_Table(VTableD);
    Print_Table(VTableC);
    Print_Table(VTableG);

    return 0;
}
