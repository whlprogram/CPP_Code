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
		data.push_back(make_pair(a, b)); //�������ݣ��������ݽṹ�ü�ֵ�Է�ʽ
	}
	sort(data.begin(), data.end(), cmp); //��ÿ��·�߽����������������·�ߵ���ʼ��Զ��

	for(int i=0; i<data.size(); i++){   //ά��һ�����䣬����̰��˼�룬����ȡ���䲢��
		cout << data[i].first << " " << data[i].second << endl;;
	}

	int max_num = 1;                     //�����������
	int counts = 1;                      //��ǰ�����ཻ����������
	int temp_start = data[0].first;
	int temp_end = data[0].second;
	for(int i=1; i<data.size(); i++){   //ά��һ�����䣬����̰��˼�룬����ȡ���䲢��
		if(data[i].first < temp_end){
			temp_start = data[i].first;
			temp_end = min(temp_end, data[i].second);
			counts++;
			if(counts > max_num)
				max_num = counts;
		}else{//���ά��������������������޽����������������䲢��ʼ����������
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
