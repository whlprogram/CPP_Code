#include <iostream>
/*
    练习二、要将”China”译成密码，
    密码规律是：用原来的字母后面第4个字母代替原来的字母。
    例如，字母A后面第4个字母是E，用E代替A。
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
    cout << "请输入加密字符串:";
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
