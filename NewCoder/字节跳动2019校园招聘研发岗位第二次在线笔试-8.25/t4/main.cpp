/*
��������ȫ������֮���������������,������Ϊ���ظ������У�
��ʵֻ���ڵ�һ������֮������������У��������е����Ԫ���ں����ÿ������֮��һ�����ڣ�
������b-1(bΪ�ظ����и���)
ans[] �洢��������
tmp[i] ��ʾ�ӵ�0λ����iλ��������и���

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    int a,b;
    scanf("%d%d", &a, &b);
    vector<int> ans(a, 0),tmp(a,1);
    for (int i = 0;i<a;i++)
    {
        scanf("%d", &ans[i]);
    }
    for (int i = 1;i<a;i++)
    {
        for (int j = 0;j<i;j++)
        {
            if (ans[i]>=ans[j])
            {
                tmp[i] = max(tmp[i], tmp[j] + 1);
            }
        }
    }
    cout << *max_element(tmp.begin(), tmp.end())+b-1;
    return 0;
}
