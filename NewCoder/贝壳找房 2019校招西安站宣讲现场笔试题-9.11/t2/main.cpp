#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first != b.first)
        return a.first < b.first;
    else if(a.first == b.first && a.second != b.second)
        return a.second < b.second;
    else
        return true;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> data;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		data.push_back(make_pair(a, b)); //接受数据，采用数据结构用键值对方式
	}
	sort(data.begin(), data.end(), cmp); //对每组路线进行排序，排序规则是路线的起始点远近

	for(int i=0; i<data.size(); i++){   //维护一个区间，采用贪心思想，不断取区间并集
		cout << data[i].first << " " << data[i].second << endl;;
	}

	int max_num = 1;                     //最大聊天人数
	int counts = 1;                      //当前区间相交最多情况人数
	int temp_start = data[0].first;
	int temp_end = data[0].second;
	for(int i=1; i<data.size(); i++){   //维护一个区间，采用贪心思想，不断取区间并集
		if(data[i].first < temp_end){
			temp_start = data[i].first;
			temp_end = min(temp_end, data[i].second);
			counts++;
			if(counts > max_num)
				max_num = counts;
		}else{//如果维护区间和现在数据区间无交集，更新数据区间并初始化聊天人数
			temp_start = data[i].first;
			temp_end = data[i].second;
			counts = 1;
		}
	}
	cout << max_num;
}
/*
3
1 3
2 5
4 6


4
4 7
2 6
2 5
1 2

4
1 2
2 5
2 7
6 9



4
1 2
2 3
3 5
5 8

4
4 7
2 6
2 3
1 2



*/
