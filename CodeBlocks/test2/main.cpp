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
    cout << "����fun1��a��ֵΪ��" << a << endl;//0  ��ֵ
    fun2(a);
    cout << "����fun2��a��ֵΪ��" << a << endl;//2  ����
    fun3(&a);
    cout << "����fun3��a��ֵΪ��" << a << endl;//3  ����ַ   �൱������
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
    cout << x << " " << y << endl;//  �����10��5
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
    cout << x << " " << y << endl;// �����5��10������ ���ã�x��y��ֵѹ����û�б仯
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
    cout << x << " " << y << endl;// 10��10
    return 0;
}
*/
