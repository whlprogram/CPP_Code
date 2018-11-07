#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    map<int, int> Map;
    int n,L;//城市个数 行动次数
    scanf("%d %d", &n, &L);
    int city[n-1];
    int res=1;
    for(int i=0; i<n-1; i++){
        scanf("%d", &city[i]);
        if(Map[city[i]] == 0 && L>0){
            res++;
            Map[city[i]] = 1;
        }
        L--;
    }
    cout << res << endl;
    return 0;
}
