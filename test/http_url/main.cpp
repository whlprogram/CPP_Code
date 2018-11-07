#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>//sstream多定义的类型则用于读写存储在内存中的string对象
using namespace std;

int main()
{
    string s = "3D";
    stringstream ss(s);//将s输入流
    cout << ss << endl;
    int value;
    //ss << value; //将int输入流
    ss >> hex >> value;//ss从流中读取s值(转换为十六进制), 再次转换为int(以十进制方式)保存在value中
    cout << value << endl;

    string out;
    out += static_cast<char>(value);//十进制强制转换为char类型
    cout << out << endl;

    int i;
    short s1;
    float f;
    double d;
    char name[80];
    scanf("%d %hd %f %lf %s", &i, &s1, &f, &d, name);
    printf("%d %d %f %f %s", i, s1, f, d, name);
    return 0;
}
