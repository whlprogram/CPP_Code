#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int Time;
    int Lv;
};
bool cmp(Node a, Node b){
    if(a.Time != b.Time)
        return a.Time>b.Time;
    else
        return a.Lv>b.Lv;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<Node> mac(n);
    vector<Node> job(m);
    for(int i=0; i<n; i++)
        cin >> mac[i].Time >>mac[i].Lv;
    for(int i=0; i<m; i++)
        cin >> job[i].Time >>job[i].Lv;
    sort(mac, mac+n, cmp);
    sort(job, job+m, cmp);
    cout << "Hello world!" << endl;
    return 0;
}
