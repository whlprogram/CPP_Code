/*
ԭ������ https://www.nowcoder.com/question/next?pid=10714908&qid=164546&tid=16850519
�ο����� https://www.nowcoder.com/discuss/82301
˼·��3��ѩ��c��һ��2�飻2��ѩ��b��һ��3�飻1��ѩ��a��һ��6�顣
step1:3��ѩ��c * 2
step2:2��ѩ��b * 3
step3:3��ѩ��c*1��2��ѩ��b*1��1��ѩ��a*1
step4:2��ѩ��b*2��1��ѩ��a*1
step5:3��ѩ��c*1��1��ѩ��a*3
step6:2��ѩ��b*1��1��ѩ��a*4
step7:1��ѩ��a*6
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, b, c;
    scanf("%d", &t);
    while(t--){
        int cont = 0;
        scanf("%d%d%d%d", &n, &a, &b, &c);
        cont += c/2;//step1:3��ѩ��c * 2
        c = c%2;
        cont += b/3;//step2:2��ѩ��b * 3
        b = b%3;
        if(a>=1 && b>=1 && c==1){//step3:3��ѩ��c*1��2��ѩ��b*1��1��ѩ��a*1
            cont += 1;
            --a;--b;--c;
        }
        if(a>=2 && b==2){//step4:2��ѩ��b*2��1��ѩ��a*1
            cont += 1;
            a -= 2;
            b = 0;
        }
        if(a>=3 && c==1){//step5:3��ѩ��c*1��1��ѩ��a*3
            cont += 1;
            a -= 3;
            c = 0;
        }
        if(a>=4 && b==1){//step6:2��ѩ��b*1��1��ѩ��a*4
            cont += 1;
            a -= 4;
            b = 0;
        }
        cont += a/6;//step7:1��ѩ��a*6
        a = a%6;
        if(cont >= n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
