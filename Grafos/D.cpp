#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (auto &a : adj) sort(a.begin(), a.end());
    while (q--) {
        int t, u, k;
        cin >> t >> u >> k;
        if (t == 1) cout << (k <= (int)adj[u].size() ? adj[u][k - 1] : -1) << '\n';
        else cout << upper_bound(adj[u].begin(), adj[u].end(), k) - adj[u].begin() << '\n';
    }

    return 0;
}
