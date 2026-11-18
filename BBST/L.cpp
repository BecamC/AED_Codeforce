#include <bits/stdc++.h>
using namespace std;

int m;
vector<long long> bit;

void add(int i, long long v)
{
    for (; i <= m; i += i & -i) bit[i] += v;
}

long long sum(int i)
{
    long long s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    vector<int> t(q);
    vector<long long> a(q), b(q);
    vector<long long> vals;
    for (int i = 0; i < q; i++) {
        cin >> t[i] >> a[i];
        if (t[i] == 3) cin >> b[i];
        else vals.push_back(a[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    m = vals.size();
    bit.assign(m + 1, 0);

    for (int i = 0; i < q; i++) {
        if (t[i] == 3) {
            int lo = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
            int hi = upper_bound(vals.begin(), vals.end(), b[i]) - vals.begin();
            cout << sum(hi) - sum(lo) << '\n';
        } else {
            int p = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
            add(p, t[i] == 1 ? a[i] : -a[i]);
        }
    }

    return 0;
}
