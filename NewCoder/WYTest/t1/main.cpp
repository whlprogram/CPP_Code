#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s = "";//选取魔法器步骤
void f1(int &n, string &s){
    n = (n-2)/2;
    s = "2" + s;
}
void f2(int &n, string &s){
     n = (n-1)/2;
     s = "1" + s;
}
int main()
{
    int n;//表示需要的魔法币数量(0<n<10^9)
    scanf("%d/n", &n);
    while(n>0){
        if(n%2 == 0)
            f1(n, s);
        else
            f2(n, s);
    }
    cout << s << endl;
    return 0;
}
