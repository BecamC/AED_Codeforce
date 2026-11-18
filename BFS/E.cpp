#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &s : g) cin >> s;
    const int INF = INT_MAX;
    vector<vector<int>> d(n, vector<int>(m, INF));
    deque<pair<int, int>> dq;
    d[0][0] = 0;
    dq.push_back({0, 0});
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int w = g[nx][ny] == '#';
            if (d[x][y] + w < d[nx][ny]) {
                d[nx][ny] = d[x][y] + w;
                if (w) dq.push_back({nx, ny});
                else dq.push_front({nx, ny});
            }
        }
    }
    cout << d[n - 1][m - 1] << '\n';

    return 0;
}
