#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s, t;
    cin >> s >> t;
    for (auto &a : adj) sort(a.begin(), a.end());
    vector<bool> vis(n + 1, false);
    vector<int> it(n + 1, 0);
    vector<int> st = {s};
    vis[s] = true;
    bool found = false;
    while (!st.empty()) {
        int u = st.back();
        if (u == t) {
            found = true;
            break;
        }
        if (it[u] < (int)adj[u].size()) {
            int v = adj[u][it[u]++];
            if (!vis[v]) {
                vis[v] = true;
                st.push_back(v);
            }
        } else st.pop_back();
    }
    if (!found) cout << "no solution\n";
    else
        for (size_t i = 0; i < st.size(); i++) cout << st[i] << (i + 1 == st.size() ? '\n' : ' ');

    return 0;
}
