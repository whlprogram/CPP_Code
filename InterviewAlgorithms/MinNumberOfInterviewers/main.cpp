//����n������ ÿ�����ݰ���һ���˵����Կ�ʼʱ��ͽ���ʱ��
//һ�����Թ�ͬʱʱ���������һ����,���������Լ���������һ����
//���ݸ��������ݣ����������Ҫ���Թٵ�����
/*
���룺
4
940 1000
950 1030
1040 1100
1030 1340

���:
2
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
struct Time{
    int Begin;
    int End;
};
bool tmp(Time a, Time b)
{
    if(a.Begin != b.Begin)
        return a.Begin<b.Begin;
    if(a.Begin==b.Begin && a.End != b.End)
        return a.End<b.End;
}
int main()
{
    int n;
    scanf("%d", &n);
    Time arr[n];
    for(int i=0; i<n; i++)
        scanf("%d %d", &arr[i].Begin, &arr[i].End);
    sort(arr, arr+n, tmp);
    printf("arr-----sort------\n");
    for(int i=0; i<n; i++)
        printf("%d %d\n", arr[i].Begin, arr[i].End);
    int res[n];//���ÿ������������ʱ�����������Ҫ���Թٵ�����
    for(int i=0; i<n; i++)
        res[i] = 1;
    for(int i=0; i<n; i++)
    {
        if(i!=0)//��arr[i]���Կ�ʼʱ���� ������arr[i]����ʱ�俪ʼʱ ��û�н������Ե�ͬѧ
        {
            for(int j=0; j<i; j++)
                if(arr[j].End > arr[i].Begin)
                    res[i]++;
        }
        if(i != (n-1))//��arr[i]���Կ�ʼʱ���� ���ǿ�ʼʱ����arr[i]���Խ���ʱ��֮ǰ��ͬѧ
        {
            for(int k=i+1; k<n; k++)
                if(arr[k].Begin < arr[i].End)
                    res[i]++;
        }
    }
    int MAX = res[0];
    for(int i=1; i<n; i++)
        if(MAX < res[i])
            MAX = res[i];
    cout << MAX << endl;
    return 0;
}
