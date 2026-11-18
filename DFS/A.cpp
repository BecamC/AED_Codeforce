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
    int islas = 0, mx = 0;
    vector<pair<int, int>> st;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '#') continue;
            islas++;
            int tam = 0;
            g[i][j] = '.';
            st.push_back({i, j});
            while (!st.empty()) {
                auto [x, y] = st.back();
                st.pop_back();
                tam++;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '#') {
                        g[nx][ny] = '.';
                        st.push_back({nx, ny});
                    }
                }
            }
            mx = max(mx, tam);
        }
    cout << islas << ' ' << mx << '\n';

    return 0;
}
