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
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    long long P = 0, c[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '#') continue;
            int k = 0;
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d], y = j + dy[d];
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '#') k++;
            }
            c[k]++;
            P += 4 - k;
        }
    cout << P << ' ' << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << ' ' << c[4] << '\n';

    return 0;
}
