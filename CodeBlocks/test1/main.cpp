#include <iostream>
#include <stdbool.h>
#include <string.h>
#include<iomanip>
using namespace std;

int main1();//��������
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
    //d=5,ֻ����hello�ĳ���,�ڽ�β�ٴ����Ҳû����("hello\0\t\\qqq"),ֻ��5,ֻ����ǰ���������,
    //ԭ����\0,����\0����Ҫ�����ֻ��,Ϊʲô?.��Ϊ����\0�ͽ���!
    //f=20,���ٵĿռ��С����,���Ƕ���,
    return 0;
}
int main3()
{
    char st[20] = "hello\t\\";//7��
    char st1[20] = "\773";//�����\ddd�����תΪ8����,\+��������  �ǰ˽��� ��һ���ֽ�
                          //\ + �������ֻ���һ������   ͬ��
                          //\x + ����  16����
    int d = strlen(st);//Ϊ7
    int e = sizeof(st);//20
    int f = strlen(st1);//Ϊ1
    cout << d << " " << e << " f=" <<f<< endl;

    char st2[20] = "89A\77";
    int m = strlen(st2);//4
    int n = sizeof(st2);//20
    cout << m <<" "<<n<< endl;

    char st3[20] = "89A\t7";
    int p1 = strlen(st3);//5
    int p2 = sizeof(st3);//20
    int p3 = strlen("asdasde\t\'\\wang\'!\t");//17   ÿ��\+��ߵ�һ�� ��һ��,\\��һ��,\a,��һ��
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
    //����const��,�����setX�Ͳ����޸�X��������
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

