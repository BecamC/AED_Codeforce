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
    vector<array<long long, 2>> d(n + 1, {INF, INF});
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    d[1][0] = 0;
    pq.push({0, 1, 0});
    while (!pq.empty()) {
        auto [du, u, p] = pq.top();
        pq.pop();
        if (du > d[u][p]) continue;
        for (auto [v, w] : adj[u])
            if (du + w < d[v][p ^ 1]) {
                d[v][p ^ 1] = du + w;
                pq.push({d[v][p ^ 1], v, p ^ 1});
            }
    }
    cout << (d[n][0] == INF ? -1 : d[n][0]) << '\n';

    return 0;
}
