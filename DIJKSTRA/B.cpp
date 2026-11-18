#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, P, Q, M;
    cin >> n >> P >> Q >> M;
    const long long INF = LLONG_MAX;
    vector<long long> d(n + 1, INF), c(n + 1, INF);
    vector<bool> done(n + 1, false);
    d[1] = 0;
    c[1] = 0;
    for (int it = 0; it < n; it++) {
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!done[i] && d[i] != INF && (u == -1 || d[i] < d[u] || (d[i] == d[u] && c[i] < c[u]))) u = i;
        if (u == -1 || u == n) break;
        done[u] = true;
        for (long long v = 1; v <= n; v++) {
            if (done[v]) continue;
            long long w = ((u + v) * P + u * v * Q) % M + 1;
            long long nd = d[u] + w, nc = c[u] + 1;
            if (nd < d[v] || (nd == d[v] && nc < c[v])) {
                d[v] = nd;
                c[v] = nc;
            }
        }
    }
    cout << d[n] << ' ' << c[n] << '\n';

    return 0;
}
