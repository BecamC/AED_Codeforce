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

    int n, q;
    cin >> n >> q;
    par.resize(n + 1);
    iota(par.begin(), par.end(), 0);
    sz.assign(n + 1, 1);
    vector<int> nodo(n + 1), caja(n + 1);
    iota(nodo.begin(), nodo.end(), 0);
    iota(caja.begin(), caja.end(), 0);
    while (q--) {
        int s, t;
        cin >> s >> t;
        if (nodo[s] == -1) continue;
        if (nodo[t] == -1) {
            nodo[t] = nodo[s];
            caja[nodo[t]] = t;
        } else {
            int a = nodo[t], b = nodo[s];
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
            nodo[t] = a;
            caja[a] = t;
        }
        nodo[s] = -1;
    }
    for (int i = 1; i <= n; i++) cout << caja[find(i)] << (i == n ? '\n' : ' ');

    return 0;
}
