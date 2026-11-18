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
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    vector<int> d((size_t)n * m * 4, -1);
    auto id = [&](int x, int y, int k) { return ((size_t)x * m + y) * 4 + k; };
    vector<int> q;
    q.reserve((size_t)n * m * 4);
    d[id(0, 0, 0)] = 0;
    q.push_back(id(0, 0, 0));
    int ans = -1;
    for (size_t h = 0; h < q.size(); h++) {
        int s = q[h];
        int k = s % 4, c = s / 4, x = c / m, y = c % m;
        if (x == n - 1 && y == m - 1) {
            ans = d[s];
            break;
        }
        int nx = x + dx[k], ny = y + dy[k];
        int nxt[3] = {-1, (int)id(x, y, (k + 1) % 4), (int)id(x, y, (k + 3) % 4)};
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '.') nxt[0] = id(nx, ny, k);
        for (int t : nxt)
            if (t != -1 && d[t] == -1) {
                d[t] = d[s] + 1;
                q.push_back(t);
            }
    }
    cout << ans << '\n';

    return 0;
}
