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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<long long> a = dijkstra(1), b = dijkstra(n);
    long long T = INF, cnt = 0;
    for (int c = 1; c <= n; c++) {
        if (a[c] == INF || b[c] == INF) continue;
        long long t = max(a[c], b[c]);
        if (t < T) {
            T = t;
            cnt = 1;
        } else if (t == T) cnt++;
    }
    if (T == INF) cout << -1 << '\n';
    else cout << T << ' ' << cnt << '\n';

    return 0;
}
