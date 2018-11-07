#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);//数列个数
    for(int i=0; i<n; i++){
        int len;
        scanf("%d", &len);
        int c1 = 0;//奇数
        int c2 = 0;//能被2整除但是不能被4整除
        int c4 = 0;//能被4整除
        for(int j=0; j<len; j++){
            int temp;
            scanf("%d", &temp);
            if(temp%4 == 0)
                c4++;
            if(temp%4!=0 && temp%2==0)
                c2++;
            if(temp%2 != 0)
                c1++;
        }
        //c2存在时，将c2的数排在一起 用一个c4连接  c1最多和c4相等
        //c2不存在时 c2的位置用一个c1代替  c1最多比c4多一个（总数len是偶数和奇数的情况一样 偶数时c1和c4做多相等 没有多出一个的情况）
        if( (c2==0 && c1<=c4+1) || (c2!=0 && c1<=c4) )
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
