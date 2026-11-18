#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    const long long INF = LLONG_MAX;
    vector<long long> d(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    d[r] = 0;
    pq.push({0, r});
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > d[u]) continue;
        for (auto [v, w] : adj[u])
            if (du + w < d[v]) {
                d[v] = du + w;
                pq.push({d[v], v});
            }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }

    return 0;
}
