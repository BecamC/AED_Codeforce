#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L;
    cin >> n >> L;
    vector<string> w(n);
    for (auto &s : w) cin >> s;
    vector<long long> deg(n, 0);
    long long m = 0;
    for (int p = 0; p < L; p++) {
        map<string, vector<int>> g;
        for (int i = 0; i < n; i++) {
            string t = w[i];
            t[p] = '*';
            g[t].push_back(i);
        }
        for (auto &kv : g) {
            long long k = kv.second.size();
            m += k * (k - 1) / 2;
            for (int i : kv.second) deg[i] += k - 1;
        }
    }
    long long mx = 0, ais = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, deg[i]);
        if (deg[i] == 0) ais++;
    }
    cout << m << ' ' << mx << ' ' << ais << '\n';

    return 0;
}
