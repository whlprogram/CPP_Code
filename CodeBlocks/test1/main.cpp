#include <iostream>
#include <stdbool.h>
#include <string.h>
#include<iomanip>
using namespace std;

int main1();//声明函数
int main2();
int main3();
int main()
{
    main1();
    main2();
    main3();
    cout  << "**************" << endl;
    char i[] = {'a','b','c','e','f'};
    int ii = strlen(i);//
    cout  << ii << endl; //
}
int main1()
{
    char a[] = "abcd";
    char b[] = {'a','b','c','e','f'};
    int d = strlen(a);//4
    int e = strlen(b);//9
    cout << d << " " << e << endl; //4  9
    cout << a[2]<<" "<<b[2]<< endl; //c  c
    return 0;
}
int main2()
{
    char st[20] = "hello\0\t\\";
    int d = strlen(st);
    int f = sizeof(st);
    cout << d <<" "<<f<< endl;//5  20
    //d=5,只计算hello的长度,在结尾再次添加也没有用("hello\0\t\\qqq"),只是5,只有在前面添加有用,
    //原因是\0,但是\0后面要是数字会变,为什么?.因为遇到\0就结束!
    //f=20,开辟的空间大小多少,就是多少,
    return 0;
}
int main3()
{
    char st[20] = "hello\t\\";//7个
    char st1[20] = "\773";//这个是\ddd后面的转为8进制,\+三个数字  是八进制 算一个字节
                          //\ + 两个数字或者一个数字   同理
                          //\x + 数字  16进制
    int d = strlen(st);//为7
    int e = sizeof(st);//20
    int f = strlen(st1);//为1
    cout << d << " " << e << " f=" <<f<< endl;

    char st2[20] = "89A\77";
    int m = strlen(st2);//4
    int n = sizeof(st2);//20
    cout << m <<" "<<n<< endl;

    char st3[20] = "89A\t7";
    int p1 = strlen(st3);//5
    int p2 = sizeof(st3);//20
    int p3 = strlen("asdasde\t\'\\wang\'!\t");//17   每个\+后边的一个 算一个,\\算一个,\a,算一个
    cout << p1 << " " << p2 << " " << p3 << endl;
}
/*
class MyClass
{
public:
    MyClass(int a);
    void SetX(int a){ X = a; }
    ~MyClass();
    void Print()const{ cout << X; }

    int X;
};

MyClass::MyClass(int a)
{
    X = a;
}

MyClass::~MyClass()
{
}
int main()
{
    //加上const后,下面的setX就不能修改X的数据了
    MyClass my(11);
    /* //20
    my.SetX(20);
    my.Print();
    */
    //11
   // my.Print();
 //   my.SetX(20);

  //  return 0;
//}

