#include <bits/stdc++.h>

using namespace std;

using Array = vector<int>;

set<int> dfs(int root, vector<Array> &sons, Array &d, int m)
{
    if (sons[root].size() == 0)
        return set<int>({0});
    vector<set<int> > sts;
    for (auto it = sons[root].begin(); it != sons[root].end(); ++it) {
            sts.push_back(dfs(*it, sons, d, m));
    }
    set<int> ret({0});
    for (auto it = sts.begin(); it != sts.end(); ++it)
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
            if (d[sons[root][it - sts.begin()]] + *it2 <= m)
                ret.insert(d[sons[root][it - sts.begin()]] + *it2);
    for (auto it_i = sts.begin(); next(it_i) != sts.end(); ++it_i) {
        for (auto it_j = it_i + 1; it_j != sts.end(); ++it_j) {
            for (auto it = it_i->begin(); it != it_i->end(); ++it) {
                for (auto it2 = it_j->begin(); it2 != it_j->end(); ++it2) {
                    if (d[sons[root][it_i - sts.begin()]] + d[sons[root][it_j - sts.begin()]] + *it + *it2 <= m)
                        ret.insert(d[sons[root][it_i - sts.begin()]] + d[sons[root][it_j - sts.begin()]] + *it + *it2);
                }
            }
        }
    }
    return ret;
}

int main()
{
    for (int m, n; cin >> m >> n; ) {
        vector<Array > sons(n);
        Array father(n, -1), d(n, 0);
        int root = 0;
        for (int i = 0, u, v, dd; i < n - 1; i++)
            cin >> u >> v >> dd, d[v] = dd, sons[u].push_back(v), father[v] = u;
        for (; root < (int)father.size() && father[root] != -1; ++root) {}
        set<int> st(dfs(root, sons, d, m));
        cout << (st.size() == 0 ? 0 : *st.rbegin()) << endl;
    }
    return 0;
}
