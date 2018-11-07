#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int l, r;
};
node Time[1000005];
bool cmp(node a, node b){
	return a.r<b.r;
}
int tt[100005];
int main()
{
	int m, n;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", &tt[i]);
	for (int i = 1; i <= n; i++){
		int x = tt[i * 2 - 1], y = tt[i * 2];
		if (x>y) y = y + m;//��ǿ���ֱ��
		Time[i].l = x;
		Time[i].r = y;
	}
	sort(Time + 1, Time + 1 + n, cmp);//����ֱ������ʱ��Ĵ��絽������
	int ans = 0;
	int overTime = 0;//��һ������ʱ��
	for (int i = 1; i <= n; i++){
		if (Time[i].l>m || Time[i].r>m) //��Ŀ��һ���ڿ����������ֱ������ �ų������ֱ��
            continue;
        //��ĿҪ�󾡿��ܶ࿴ֱ����ÿ��ѡ������һ������ʱ�������ֱ��
        //�����Ѿ�������ʱ������ÿ��ѡ�еĶ��ǼȲ����ϳ���ͻ�������������ֱ��
		if (Time[i].l >= overTime){
			ans++;
			overTime = Time[i].r;
		}
		if(overTime == m)
            break;
	}
	cout << ans << endl;
	return 0;
}

