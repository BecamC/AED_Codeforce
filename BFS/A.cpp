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
    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') sx = i, sy = j;
            if (g[i][j] == 'E') ex = i, ey = j;
        }
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    d[sx][sy] = 0;
    q.push({sx, sy});
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#' || d[nx][ny] != -1) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << d[ex][ey] << '\n';

    return 0;
}
