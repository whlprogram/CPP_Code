/*
Printf和cout混用的问题
https://bbs.csdn.net/topics/360174455
https://blog.csdn.net/qq_28236309/article/details/52200632
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int j=0;
    for(j=0;j<5;j++){
        ios::sync_with_stdio(false);
        //ios::sync_with_stdio(true);
        //cout << flush;
        cout << "j=";
        cout << flush;//刷新缓冲区
        printf("%d\n", j);
        //cout << flush;
        //cout.flush();
        //cout << endl;
    }

    return 0;
}
