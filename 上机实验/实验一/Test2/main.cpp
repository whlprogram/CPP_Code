#include <iostream>
/*
    ��ϰ����Ҫ����China��������룬
    ��������ǣ���ԭ������ĸ�����4����ĸ����ԭ������ĸ��
    ���磬��ĸA�����4����ĸ��E����E����A��
    China
    Glmre
*/
using namespace std;

int main()
{
    string x = "";
    char xArray[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                     'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                     'a','b','c','d','e','f','g','h','i','j','k','l','m',
                     'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cout << "����������ַ���:";
    cin >> x;
    for(int m = 0; m < x.length(); m++)
    {
        for(int i = 0; i < 52; i++)
        {
            if (x[m] == xArray[i])
            {
                i = i + 4;
                if(i >= 52)
                    i = 51;
                x[m] = xArray[i];
            }
        }
    }
    cout << x << endl;
    return 0;
}
