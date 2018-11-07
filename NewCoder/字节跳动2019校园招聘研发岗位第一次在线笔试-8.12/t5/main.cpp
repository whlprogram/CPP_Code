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
		if (x>y) y = y + m;//标记跨天直播
		Time[i].l = x;
		Time[i].r = y;
	}
	sort(Time + 1, Time + 1 + n, cmp);//按照直播结束时间的从早到晚排序
	int ans = 0;
	int overTime = 0;//上一场结束时间
	for (int i = 1; i <= n; i++){
		if (Time[i].l>m || Time[i].r>m) //题目求一天内看的最多完整直播场数 排除跨天的直播
            continue;
        //题目要求尽可能多看直播，每次选择离上一场结束时间最近的直播
        //由于已经按结束时间排序，每次选中的都是既不和上场冲突，结束又最早的直播
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

