/*��ϰһ������һ��ʱ����Date���������ݳ�Ա�ꡢ�¡���
��1�����ù��캯����ɳ�ʼ�����ݳ�Ա����֤�ꡢ�¡��յ�ֵ��ȷ������·ݳ���������Χ��������Ϊ1��
    �����������캯�������ι��졢���ι�����޲ι���
��2�����ݳ�Ա��Ϊ˽�г�Աͨ��get��set�������з���
��3�������Ա����displayDate��ʵ���������ʽҪ����/��/��
��4����Ա����Ҫ���������������������ⶨ��
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
