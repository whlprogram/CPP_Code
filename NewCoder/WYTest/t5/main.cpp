#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);//���и���
    for(int i=0; i<n; i++){
        int len;
        scanf("%d", &len);
        int c1 = 0;//����
        int c2 = 0;//�ܱ�2�������ǲ��ܱ�4����
        int c4 = 0;//�ܱ�4����
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
        //c2����ʱ����c2��������һ�� ��һ��c4����  c1����c4���
        //c2������ʱ c2��λ����һ��c1����  c1����c4��һ��������len��ż�������������һ�� ż��ʱc1��c4������� û�ж��һ���������
        if( (c2==0 && c1<=c4+1) || (c2!=0 && c1<=c4) )
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
