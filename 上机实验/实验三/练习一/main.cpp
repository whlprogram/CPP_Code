#include <iostream>
//#include <STDARG.H>
/*
    ��д������֤��°ͺղ��룺һ����С6��ż�����Ա�ʾΪ��������֮�ͣ���6=3+3,8=3+5,10=3+7,��..��
    ��������������һ����С��6��ż��n��Ȼ����ú���gotbaha����gotbaha�����е���prime������
    prime�������������б�һ�����Ƿ�Ϊ������
*/
using namespace std;
bool prime(int);
void gotbaha(int);
int main()
{
    int a = 0;
    cout << "������һ�����ڣ����ڣ�6��ż����";
    cin >> a;
    while (a%2 != 0 || a < 6)
    {
        cout << "���������룺";
        cin >> a;
    }
    gotbaha(a);
    return 0;
}
bool prime(int num)//�ж��Ƿ�Ϊ����
{
    for(int i=2;i<num;i++)
    {
        if(num % i == 0)
        {
            return false;//0
            break;
        }
    }
    return true;//1
}
void gotbaha(int num)//�ҳ�������������������
{
    for(int subtrahend_1=3; subtrahend_1 <= num/2; subtrahend_1++)
    {
        if(prime(subtrahend_1) == 1)//��һ���������жϣ�����prime()����
        {
           int subtrahend_2 = num - subtrahend_1;
           if(prime(subtrahend_2) == 1)//�ڶ����������жϣ�����prime()����
           {
                cout << num << "=" << subtrahend_1 << "+" << subtrahend_2 << endl;
           }
        }
    }
}
