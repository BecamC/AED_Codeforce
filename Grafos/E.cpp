#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> e(m);
    for (auto &x : e) {
        long long u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        x = u * 300000 + v;
    }
    sort(e.begin(), e.end());
    while (q--) {
        long long u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        long long k = u * 300000 + v;
        cout << upper_bound(e.begin(), e.end(), k) - lower_bound(e.begin(), e.end(), k) << '\n';
    }

    return 0;
}
