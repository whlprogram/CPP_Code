#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int n=2001, m=101;
int main()
{
    cin >> n >> m;
    int a[n+1];
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    int q;
    cin >> q;
    for(int i=0; i<q; ++i){
        int l, r;
        cin >> l >> r;
        set<int> myset;
        for(int j=l; j<=r; ++j) {
            myset.insert(a[j]);
        }
        cout << myset.size() << endl;
    }
    return 0;
}
