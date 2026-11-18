#include <bits/stdc++.h>
using namespace std;

bitset<3001> adj[3001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e(m);
    for (auto &p : e) {
        cin >> p.first >> p.second;
        adj[p.first][p.second] = 1;
        adj[p.second][p.first] = 1;
    }
    long long c = 0;
    for (auto &p : e) c += (adj[p.first] & adj[p.second]).count();
    cout << c / 3 << '\n';

    return 0;
}
