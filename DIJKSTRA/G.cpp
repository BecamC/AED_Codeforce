#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    int L = 2 * n;
    const long long INF = LLONG_MAX;
    vector<long long> d(L + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > d[u]) continue;
        if (u == n) break;
        pair<long long, long long> mv[3] = {{u + 1, a}, {u - 1, b}, {2LL * u, c}};
        for (auto [v, w] : mv)
            if (v >= 1 && v <= L && du + w < d[v]) {
                d[v] = du + w;
                pq.push({d[v], (int)v});
            }
    }
    cout << d[n] << '\n';

    return 0;
}
