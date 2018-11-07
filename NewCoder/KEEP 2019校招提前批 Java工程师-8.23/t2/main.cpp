#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool flag = true;
    for(int i=0,j=s.size()-1; i<j; ++i,--j)
    {
        if(s[i] != s[j])
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        for(int i=0; i<s.size()-1; ++i)
        {
            printf("1,");
        }
        printf("1\n");
    }
    else
    {
        for(int i=0; i<s.size()-1; ++i)
        {
            if(s[i] == 'a')
                printf("1,");
            else
                printf("2,");
        }
        if(s[s.size()-1] == 'a')
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
