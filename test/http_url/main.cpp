#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>//sstream�ඨ������������ڶ�д�洢���ڴ��е�string����
using namespace std;

int main()
{
    string s = "3D";
    stringstream ss(s);//��s������
    cout << ss << endl;
    int value;
    //ss << value; //��int������
    ss >> hex >> value;//ss�����ж�ȡsֵ(ת��Ϊʮ������), �ٴ�ת��Ϊint(��ʮ���Ʒ�ʽ)������value��
    cout << value << endl;

    string out;
    out += static_cast<char>(value);//ʮ����ǿ��ת��Ϊchar����
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
