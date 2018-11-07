#include<stdio.h>

//原理：2的幂的二进制位中有且只有一位是1
int Is2Power(unsigned int d)
{
    int i = sizeof(d) << 3;  //这里i得到d所占的位数(bits)，因为要对d的每一位作判断
    unsigned int v;
    while(i > 0)
    {
        v = 1 & d;    //取得d的最后一位
        d >>= 1;
        if(v == 1)
        {
            if(d == 0)
                return 1;  //是2的幂
            else
                return 0;  //不是2的幂
        }
        i--;
    }
    return 0;
}

int main()
{
    unsigned int d;
    int i = 0;
    while(i < 9999)
    {
        if(Is2Power(i))
            printf("%d  is 2's Power.\n", i);
        i++;
    }
    return 0;
}
