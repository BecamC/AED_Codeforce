#include <bits/stdc++.h>
using namespace std;

vector<int> par, ans;
vector<vector<int>> mem;
vector<bool> has1;

int find(int x)
{
    while (par[x] != x) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void unite(int a, int b, int t)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (has1[a] != has1[b] && t >= 0) {
        int c = has1[a] ? b : a;
        for (int x : mem[c]) ans[x] = t;
    }
    if (mem[a].size() < mem[b].size()) swap(a, b);
    par[b] = a;
    for (int x : mem[b]) mem[a].push_back(x);
    vector<int>().swap(mem[b]);
    has1[a] = has1[a] || has1[b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i][1] >> h[i][2];
    vector<array<int, 3>> rel(n + 1, {-1, -1, -1});
    vector<int> em(m), eh(m);
    for (int i = 0; i < m; i++) {
        cin >> em[i] >> eh[i];
        if (rel[em[i]][eh[i]] == -1) rel[em[i]][eh[i]] = i;
    }
    par.resize(n + 1);
    iota(par.begin(), par.end(), 0);
    mem.assign(n + 1, {});
    for (int i = 1; i <= n; i++) mem[i].push_back(i);
    has1.assign(n + 1, false);
    has1[1] = true;
    ans.assign(n + 1, -1);
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= 2; k++)
            if (h[i][k] != -1 && rel[i][k] == -1) unite(i, h[i][k], -1);
    for (int i = m - 1; i >= 0; i--) {
        int x = em[i], k = eh[i];
        if (rel[x][k] != i || h[x][k] == -1) continue;
        unite(x, h[x][k], i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';

    return 0;
}
