#include <iostream>
#define S1(a, b, c) (a+b+c)/2
#define area(s,a,b,c) s*(s-a)*(s-b)*(s-c)

using namespace std;

int main()
{
    int a = 0,b = 0,c = 0,s = 0;
    cout << "请输入a,b,c的三边：" << endl;
    cin >> a >> b >> c;
    s = S1(a, b, c);
    int Area = area(s,a,b,c);
    cout << "三角形面积=" << s  << " " << "Area=" << Area << endl;
    return 0;
}
