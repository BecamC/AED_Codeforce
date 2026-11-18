#include <bits/stdc++.h>
using namespace std;

vector<int> par, sz;
vector<long long> val;

int find(int x)
{
    while (par[x] != x) x = par[x];
    return x;
}

long long get(int x)
{
    long long s = 0;
    while (true) {
        s += val[x];
        if (par[x] == x) break;
        x = par[x];
    }
    return s;
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    val[b] -= val[a];
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
    val.assign(n + 1, 0);
    while (m--) {
        string op;
        cin >> op;
        if (op == "join") {
            int x, y;
            cin >> x >> y;
            unite(x, y);
        } else if (op == "add") {
            int x;
            long long v;
            cin >> x >> v;
            val[find(x)] += v;
        } else {
            int x;
            cin >> x;
            cout << get(x) << '\n';
        }
    }

    return 0;
}
