#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
    }
    vector<int> col(n, 0), it(n, 0), pe(n, -1);
    vector<int> st;
    for (int r = 0; r < n; r++) {
        if (col[r]) continue;
        col[r] = 1;
        st.push_back(r);
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)adj[u].size()) {
                auto [v, id] = adj[u][it[u]++];
                if (col[v] == 0) {
                    col[v] = 1;
                    pe[v] = id;
                    st.push_back(v);
                } else if (col[v] == 1) {
                    vector<int> ans;
                    int k = st.size() - 1;
                    while (st[k] != v) {
                        ans.push_back(pe[st[k]]);
                        k--;
                    }
                    reverse(ans.begin(), ans.end());
                    ans.push_back(id);
                    cout << ans.size() << '\n';
                    for (int e : ans) cout << e << '\n';
                    return 0;
                }
            } else {
                col[u] = 2;
                st.pop_back();
            }
        }
    }
    cout << -1 << '\n';

    return 0;
}
