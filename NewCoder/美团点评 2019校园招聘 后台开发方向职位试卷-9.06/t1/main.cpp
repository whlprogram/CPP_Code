#include <iostream>
int depth[100005];
using namespace std;

int main(){
	int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >>a >> b;
        depth[b] = depth[a] + 1;//��ǰ�ڵ�����
    }
    int maxDepth = 0;
    for(int i=1; i<=n; i++)
        maxDepth = depth[i]>maxDepth ? depth[i] : maxDepth;//Ѱ�����ֵ
    cout << 2*(n-1)-maxDepth << endl;
    return 0;
}
/*
4
1 2
1 3
3 4
*/
