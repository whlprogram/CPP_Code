//�����ꡢ�¡��գ���������Ǹ���ĵڼ���
#include <iostream>

using namespace std;

int main()
{
    cout << "�������� �� �գ�" << endl;
    int a=0,b=0,c=0;
    cin >> a;
    cin >> b;
    cin >> c;
    int arr[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //�ж��Ƿ�������
    if(a%4==0 && a%100!=0)
    {
        arr[1] = 29;
    }
    //�ж�����
    int sum = 0;
    for(int i =0;i< b-1;i++)
    {
        sum += arr[i];
    }
    sum += c;
    cout << a << "/" << b << "/" << c << "��ȫ��ĵ�" << sum << "��"<< endl;
    return 0;
}
