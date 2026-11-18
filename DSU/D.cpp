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

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
    }
    vector<string> op(k);
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) cin >> op[i] >> a[i] >> b[i];
    par.resize(n + 1);
    iota(par.begin(), par.end(), 0);
    sz.assign(n + 1, 1);
    vector<bool> res;
    for (int i = k - 1; i >= 0; i--) {
        if (op[i] == "cut") unite(a[i], b[i]);
        else res.push_back(find(a[i]) == find(b[i]));
    }
    reverse(res.begin(), res.end());
    for (bool r : res) cout << (r ? "YES" : "NO") << '\n';

    return 0;
}
