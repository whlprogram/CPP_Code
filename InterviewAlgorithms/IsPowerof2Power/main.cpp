#include<stdio.h>

//ԭ��2���ݵĶ�����λ������ֻ��һλ��1
int Is2Power(unsigned int d)
{
    int i = sizeof(d) << 3;  //����i�õ�d��ռ��λ��(bits)����ΪҪ��d��ÿһλ���ж�
    unsigned int v;
    while(i > 0)
    {
        v = 1 & d;    //ȡ��d�����һλ
        d >>= 1;
        if(v == 1)
        {
            if(d == 0)
                return 1;  //��2����
            else
                return 0;  //����2����
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
