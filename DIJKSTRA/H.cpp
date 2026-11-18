#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    const long long INF = LLONG_MAX;
    vector<long long> d1(n + 1, INF), d2(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    d1[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > d2[u]) continue;
        for (auto [v, w] : adj[u]) {
            long long nd = du + w;
            if (nd < d1[v]) {
                d2[v] = d1[v];
                d1[v] = nd;
                pq.push({d1[v], v});
                if (d2[v] != INF) pq.push({d2[v], v});
            } else if (nd > d1[v] && nd < d2[v]) {
                d2[v] = nd;
                pq.push({d2[v], v});
            }
        }
    }
    cout << (d2[n] == INF ? -1 : d2[n]) << '\n';

    return 0;
}
