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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> eu(n - 1), ev(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> eu[i] >> ev[i];
    par.resize(n + 1);
    sz.resize(n + 1);

    auto calc = [&](bool mx) {
        vector<int> idx(n - 1);
        vector<int> key(n - 1);
        for (int i = 0; i < n - 1; i++) key[i] = mx ? max(a[eu[i]], a[ev[i]]) : min(a[eu[i]], a[ev[i]]);
        iota(idx.begin(), idx.end(), 0);
        if (mx) sort(idx.begin(), idx.end(), [&](int x, int y) { return key[x] < key[y]; });
        else sort(idx.begin(), idx.end(), [&](int x, int y) { return key[x] > key[y]; });
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        long long s = 0;
        for (int i : idx) {
            int x = find(eu[i]), y = find(ev[i]);
            s += (long long)sz[x] * sz[y] * key[i];
            if (sz[x] < sz[y]) swap(x, y);
            par[y] = x;
            sz[x] += sz[y];
        }
        return s;
    };

    cout << calc(true) - calc(false) << '\n';

    return 0;
}
