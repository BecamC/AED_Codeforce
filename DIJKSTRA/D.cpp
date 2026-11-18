#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
int n, m;
vector<vector<pair<int, long long>>> adj;

vector<long long> dijkstra(int s)
{
    vector<long long> d(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    d[s] = 0;
    pq.push({0, s});
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
    return d;
}

long long suma(long long x, long long y, long long z)
{
    if (x == INF || y == INF || z == INF) return INF;
    return x + y + z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> n >> m >> a >> b;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<long long> d1 = dijkstra(1), da = dijkstra(a), db = dijkstra(b);
    long long ans = min(suma(d1[a], da[b], db[n]), suma(d1[b], db[a], da[n]));
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}
