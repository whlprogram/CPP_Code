#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if(a<0 || a>99999)
        return 0;
    if(a == 0)
    {
        cout << "L" << endl;
        return 0;
    }
    char arr[] = {'L', 'S', 'B', 'Q', 'W'};
    string res = "";
    bool flag = false;//�ж�λ��Ϊ0��ǰ���Ƿ���ֵ
    //����101��ʮλ�ϵ�0ǰ����ֵ(����λ�ϵ�1) flag = true
    //����100��ʮλ�ϵ�0ǰ��û��ֵ flag = false
    int i = 0;
    while(a != 0)
    {
        int temp = a%10;
        if(temp != 0)
        {
            flag = true;
            if(i != 0)
                res = arr[i] + res;
            char c = '0' + temp;
            res = c + res;
        }
        else if(temp == 0 && i!=0 && flag)
        {
            res = arr[0] + res;
            flag = false;
        }
        i++;
        a /= 10;
    }
    cout << res << endl;
    return 0;
}
