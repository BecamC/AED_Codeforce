#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(n + 1, -1);
    queue<int> q;
    for (int i = 0; i < k; i++) {
        int h;
        cin >> h;
        d[h] = 0;
        q.push(h);
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
    for (int i = 1; i <= n; i++) cout << d[i] << (i == n ? '\n' : ' ');

    return 0;
}
