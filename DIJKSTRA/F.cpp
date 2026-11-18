#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    const long long INF = LLONG_MAX;
    vector<long long> d(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > d[u]) continue;
        if (u == n) break;
        long long sal = (du + c[u] - 1) / c[u] * c[u];
        for (auto [v, w] : adj[u])
            if (sal + w < d[v]) {
                d[v] = sal + w;
                pq.push({d[v], v});
            }
    }
    cout << (d[n] == INF ? -1 : d[n]) << '\n';

    return 0;
}
