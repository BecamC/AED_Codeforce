#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, C;
    cin >> n >> m >> C;
    vector<long long> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    const long long INF = LLONG_MAX;
    vector<vector<long long>> d(n + 1, vector<long long>(C + 1, INF));
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    d[1][0] = 0;
    pq.push({0, 1, 0});
    long long ans = -1;
    while (!pq.empty()) {
        auto [du, u, f] = pq.top();
        pq.pop();
        if (du > d[u][f]) continue;
        if (u == n) {
            ans = du;
            break;
        }
        if (f < C && du + p[u] < d[u][f + 1]) {
            d[u][f + 1] = du + p[u];
            pq.push({d[u][f + 1], u, f + 1});
        }
        for (auto [v, l] : adj[u])
            if (f >= l && du < d[v][f - l]) {
                d[v][f - l] = du;
                pq.push({du, v, f - l});
            }
    }
    cout << ans << '\n';

    return 0;
}
