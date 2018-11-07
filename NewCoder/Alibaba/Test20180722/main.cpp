/*
今天我们看到的阿里巴巴提供的任何一项服务后边都有着无数子系统和组件的支撑，子系统之间也互相依赖关联，
其中任意一个环节出现问题都可能对上游链路产生影响。小明做为新人接收到的第一个任务就是去梳理所有的依赖关系，
小明和每个系统的负责人确认了依赖关系，记录下调用对应系统的耗时，用这些数据分析端到端链路的数目和链路上最长的耗时。
输入： 小明搜集到的系统耗时和依赖列表
5  4   // 表示有5个系统和 4个依赖关系
3      // 调用1号系统耗时 3 ms
2      // 调用2号系统耗时 2 ms
10     // 调用3号系统耗时 10 ms
5      // 调用4号系统耗时 5 ms
7      //  调用5号系统耗时 7 ms
1 2    //  2号系统依赖1号系统
1 3    //  3号系统依赖1号系统
2 5    //  2号系统依赖5号系统
4 5    //  4号系统依赖5号系统
输出:  调用链路的数目 和最大的耗时， 这里有三条链路1->2->5，1->3， 4->5，最大的耗时是1到3的链路 3+10 = 13，无需考虑环形依赖的存在。


输入：
5 4
3
2
10
5
7
1 2
1 3
2 5
4 5
输出：
3  13
*/
//典型的最小生成树问题，根据权值计算出最大的路径。
//用一个vector保存每个系统的耗时useTime
//用一个multimap保存依赖关系树Map
//保存一个是否是根系统的布尔数组isRoot

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

void fun(multimap<int, int> &Map, vector<double> &useTime, vector<int>& path, vector<vector<int> > &paths, int key, int &time, int &maxTime) {
    multimap<int, int>::iterator iter;
    time += useTime[key];
    path.push_back(key);

    if ((iter = Map.find(key)) != Map.end()) {//有son
        int n = Map.count(key);//统计该结点有多少依赖关系
        for (int j = 0; j < n; ++j, ++iter) {//遍历所有son
            fun(Map, useTime, path, paths, iter->second, time, maxTime);
        }
    } else {//路径尽头
        paths.push_back(path);
        if (maxTime < time)
            maxTime = time;
    }

    time -= useTime[key];//去掉已经访问过节点的时间
    path.pop_back();//弹出已经访问过的结点
}
int main()
{
    int m, n;
    cin >> m >> n;//m个系统 n个依赖关系
    vector<double> useTime(m+1);//保存时间
    bool* isRoot = new bool[m + 1];//该系统是否是根系统
    memset(isRoot, 1, m + 1);//首先全部置为true
    multimap<int, int> Map;//依赖关系map
    int maxTime = 0;//需要返回的最大的耗时
    vector<vector<int> > paths;//记录所有路径
    for (int i=1; i<=m; ++i) {
        double time;
        cin >> time;
        useTime[i] = time;
    }
    for (int i=0; i<n; ++i) {
        int father, son;
        cin >> father >> son;
        Map.insert(make_pair(father, son));
        isRoot[son] = false;//son不是根系统
    }

    for (int i=1; i<=m; ++i) {
        if (isRoot[i]) {//如果是根系统
            int time = 0;
            vector<int> path;
            fun(Map, useTime, path, paths, i, time, maxTime);
        }
    }
    delete[] isRoot;
    cout << paths.size() << " " << maxTime << endl;
    return 0;
}


