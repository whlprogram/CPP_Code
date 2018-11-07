#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct GraphNode{
     int label;
     vector<GraphNode *> neighbor;//节点能够直接到达的城市 直接出度
	 vector<GraphNode *> gety;//能够直接到达该节点的城市 直接入度
     GraphNode(int x) : label(x) {};
};
//利用队列计算节点出度
int get_x(vector<GraphNode *> graph, int i, vector<int> visit){
	 visit[i] = 1;
	 int counts = 0;
	 queue<GraphNode *> data;
	 data.push(graph[i]);
	 while(!data.empty()){
		 GraphNode *p = data.front();
		 data.pop();
		 for(int j=0; j < p->neighbor.size(); j++){
			 if(visit[p->neighbor[j]->label] == -1){
				 data.push(graph[p->neighbor[j]->label]);
				 visit[p->neighbor[j]->label] = 1;
				 counts++;
			 }
		 }
	 }
    return counts;
}
//利用队列计算节点入度
int get_y(vector<GraphNode *> graph, int i, vector<int> visit){
	 visit[i] = 1;
	 int counts = 0;
	 queue<GraphNode *> data;
	 data.push(graph[i]);
	 while(!data.empty()){
		 GraphNode *p = data.front();
		 data.pop();
		 for(int j=0; j<p->gety.size(); j++){
			 if(visit[p->gety[j]->label] == -1){
				 data.push(graph[p->gety[j]->label]);
				 visit[p->gety[j]->label] = 1;
				 counts++;
			 }
		 }
	 }
	 return counts;
}
int fun(vector<GraphNode *> graph, vector<int> visit){
	 int result = 0;
	 for(int i=0; i<graph.size(); i++){
		 int x = get_x(graph,i,visit);//计算节点出度
		 int y = get_y(graph,i,visit);//计算节点入度
		 cout << x << " " << y << endl;
		 if(x < y)
			 result++;
	 }
	 return result;
}
int main()
{
	int n, m;
	vector<pair<int,int>> data;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		data.push_back(make_pair(a, b));
	}
	vector<GraphNode *> graph;
    vector<int> visit;//记录已经遍历过的节点
    for(int i=0; i<n; i++){
        graph.push_back(new GraphNode(i));
        visit.push_back(-1);
    }
    for(int i=0; i<data.size(); i++){
        int begin = data[i].first;
        int end = data[i].second;
        graph[begin-1]->neighbor.push_back(graph[end-1]);
		graph[end-1]->gety.push_back(graph[begin-1]);
    }
	int res = fun(graph, visit);
	cout << res;
}
/*
4 3
2 1
3 2
4 3
*/

/*
#include <bits/stdc++.h>

using namespace std;
int n, m;
struct node{
    int id;
    int in;
    int out;
    vector<int> arrIn;
};
int main()
{
    cin >> n >> m;
    vector<node> arr(n+1);
    int temp_in, temp_out;
    for(int i=0; i<=n; i++){
        arr[i].id = i;
    }
    for(int i=0; i<m; i++){
        cin >> temp_in >> temp_out;
        arr[temp_in].out++;
        arr[temp_out].in++;
        arr[temp_out].arrIn.push_back(temp_in);
    }
    for(int i=1; i<arr.size(); i++){
        int len = arr[i].arrIn.size();
        if(len > 0){
            for(int j=0; j<len; j++){
                int temp = arr[i].arrIn[j];
                arr[i].in += arr[temp].in;
            }
        }
    }
    int res = 0;
    for(int i=1; i<arr.size(); i++){
        if(arr[i].in > arr[i].out){
            res++;
            //cout << i << endl;
        }
    }
    cout << res << endl;
    return 0;
}
*/

