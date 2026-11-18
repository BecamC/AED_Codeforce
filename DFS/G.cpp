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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (m != n - 1) {
        cout << "NO\n";
        return 0;
    }
    vector<bool> vis(n + 1, false);
    vector<int> st = {1};
    vis[1] = true;
    int cnt = 0;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        cnt++;
        for (int v : adj[u])
            if (!vis[v]) {
                vis[v] = true;
                st.push_back(v);
            }
    }
    cout << (cnt == n ? "YES" : "NO") << '\n';

    return 0;
}
