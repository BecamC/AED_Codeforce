#include <bits/stdc++.h>
using namespace std;

vector<int> par, sz;

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
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    sz.assign(n + 1, 1);
    iota(par.begin(), par.end(), 0);
    while (m--) {
        string op;
        int u, v;
        cin >> op >> u >> v;
        if (op == "union") unite(u, v);
        else cout << (find(u) == find(v) ? "YES" : "NO") << '\n';
    }

    return 0;
}
