#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n + 1), tout(n + 1), par(n + 1, 0), it(n + 1, 0);
    int timer = 0;
    vector<int> st = {1};
    tin[1] = timer++;
    while (!st.empty()) {
        int u = st.back();
        if (it[u] < (int)adj[u].size()) {
            int v = adj[u][it[u]++];
            if (v == par[u]) continue;
            par[v] = u;
            tin[v] = timer++;
            st.push_back(v);
        } else {
            tout[u] = timer++;
            st.pop_back();
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (tin[u] <= tin[v] && tout[v] <= tout[u] ? "SI" : "NO") << '\n';
    }

    return 0;
}
