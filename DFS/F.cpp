#include <bits/stdc++.h>
using namespace std;

int n, m;
bool adj[101][101];
bool usado[101];

bool puede(int x, int a1, int j)
{
    vector<bool> vis(n + 1, false);
    vector<int> st = {x};
    vis[x] = true;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        if (adj[u][a1] && (j >= 2 || u != x)) return true;
        for (int w = 1; w <= n; w++)
            if (adj[u][w] && !vis[w] && !usado[w] && w != a1) {
                vis[w] = true;
                st.push_back(w);
            }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }
    for (int a1 = 1; a1 <= n; a1++) {
        memset(usado, 0, sizeof(usado));
        usado[a1] = true;
        vector<int> path = {a1};
        while (true) {
            int u = path.back();
            int j = path.size();
            if (j >= 3 && adj[u][a1]) break;
            int nx = -1;
            for (int x = 1; x <= n; x++)
                if (adj[u][x] && !usado[x] && puede(x, a1, j)) {
                    nx = x;
                    break;
                }
            if (nx == -1) break;
            usado[nx] = true;
            path.push_back(nx);
        }
        if (path.size() >= 3 && adj[path.back()][a1]) {
            cout << "YES\n" << path.size() << '\n';
            for (int x : path) cout << x << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}
