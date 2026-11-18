#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1, 0);
    vector<pair<int, int>> e(m);
    for (auto &p : e) {
        cin >> p.first >> p.second;
        in[p.second]++;
    }
    sort(e.begin(), e.end());
    long long mut = 0;
    for (auto &p : e)
        if (p.first < p.second && binary_search(e.begin(), e.end(), make_pair(p.second, p.first))) mut++;
    int best = 1;
    for (int i = 2; i <= n; i++)
        if (in[i] > in[best]) best = i;
    cout << mut << ' ' << best << ' ' << in[best] << '\n';

    return 0;
}
