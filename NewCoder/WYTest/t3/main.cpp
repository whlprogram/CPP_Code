#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s == ""){
        return 0;
    }
    if(s.size() == 1){
        printf("1");
        return 0;
    }
    double len = 0;//总长度
    double con = 0;//碎片数量
    double temp = 1;//初始化碎片长度
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            temp++;
        }else{
            len += temp;
            con++;
            temp = 1;
        }
    }
    len += temp;//加上最后一片碎片
    con++;//算上最后一片碎片得出碎片总数

    printf("%.2f", len/con);
    return 0;
}
