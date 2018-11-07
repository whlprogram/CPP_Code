#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        int con = 0;
        int temp = 0;
        int flag = 0;//第一个需要光照的格子
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            if(s[j]=='.')
                break;
            flag++;
        }
        for(int j=flag; j<n; j++){
            if(s[j]=='X'&& temp==0)
                continue;
            temp++;
            if(temp == 3){
                con++;
                temp = 0;
            }
        }
        if(temp != 0)
            con++;
        printf("%d\n", con);
    }
    return 0;
}
