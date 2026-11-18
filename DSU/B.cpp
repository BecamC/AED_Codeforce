#include <bits/stdc++.h>
using namespace std;

vector<int> par, sz, mn, mx;

int find(int x)
{
    while (par[x] != x) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    mn[a] = min(mn[a], mn[b]);
    mx[a] = max(mx[a], mx[b]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    iota(par.begin(), par.end(), 0);
    sz.assign(n + 1, 1);
    mn = par;
    mx = par;
    while (m--) {
        string op;
        cin >> op;
        if (op == "union") {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v;
            cin >> v;
            int r = find(v);
            cout << mn[r] << ' ' << mx[r] << ' ' << sz[r] << '\n';
        }
    }

    return 0;
}
