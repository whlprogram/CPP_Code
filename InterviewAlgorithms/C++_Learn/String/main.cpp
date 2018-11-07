#include "string.h"
#include <iostream>

using namespace std;

int main()
{
    String s1("hello");
    String s2("world");
    String s3(s2);

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    s3 = s1;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    String s4("www");
    String s5("hhhlll");
    cout << "s4 : " << s4.get_c_str() << endl;
    cout << "s5 : " << s5.get_c_str() << endl;
    int s4strlen = strlen(s4.get_c_str());
    cout << "s4 strlen: " << s4strlen << endl;
    cout << "s5 strlen: " << strlen(s5.get_c_str()) << endl;

    strcpy(s4.get_c_str(), s5.get_c_str());

    cout << "s4 : " << s4.get_c_str() << endl;
    cout << "s5 : " << s5.get_c_str() << endl;
    cout << "Hello world!" << endl;
    return 0;
}
