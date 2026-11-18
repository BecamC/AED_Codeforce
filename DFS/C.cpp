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
    }
    for (auto &a : adj) sort(a.begin(), a.end());
    vector<int> tin(n + 1, -1), it(n + 1, 0);
    vector<bool> fin(n + 1, false);
    long long arbol = 0, ret = 0, ava = 0, cru = 0;
    int timer = 0;
    vector<int> st;
    for (int r = 1; r <= n; r++) {
        if (tin[r] != -1) continue;
        tin[r] = timer++;
        st.push_back(r);
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                if (tin[v] == -1) {
                    arbol++;
                    tin[v] = timer++;
                    st.push_back(v);
                } else if (!fin[v]) ret++;
                else if (tin[v] > tin[u]) ava++;
                else cru++;
            } else {
                fin[u] = true;
                st.pop_back();
            }
        }
    }
    cout << arbol << ' ' << ret << ' ' << ava << ' ' << cru << '\n';

    return 0;
}
