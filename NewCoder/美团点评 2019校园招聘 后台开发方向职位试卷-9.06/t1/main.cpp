#include <iostream>
int depth[100005];
using namespace std;

int main(){
	int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >>a >> b;
        depth[b] = depth[a] + 1;//当前节点的深度
    }
    int maxDepth = 0;
    for(int i=1; i<=n; i++)
        maxDepth = depth[i]>maxDepth ? depth[i] : maxDepth;//寻找最大值
    cout << 2*(n-1)-maxDepth << endl;
    return 0;
}
/*
4
1 2
1 3
3 4
*/
