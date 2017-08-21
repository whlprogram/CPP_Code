#include <iostream>

using namespace std;

int main()
{
    int a=8;
    int b=2;
    int c = ++a+=b;
    cout << c << endl;
    if((a==2)&&(b==1))
        cout << "sdfsefsfs" << endl;
    cout << "----------" << endl;
    string s="vm\x43\\\np\101qu";
    string s1="\x43";
    string s2="\x43";
    cout << s << endl;
    cout << s.length() << endl;
    cout << s1 << endl;
    cout << s1.length() << endl;
    cout << s2 << endl;
    cout << s2.length() << endl;
    return 0;
}
