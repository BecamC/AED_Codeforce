#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 1000000007;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> col(n + 1, -1);
    long long ans = 1;
    bool ok = true;
    for (int s = 1; s <= n && ok; s++) {
        if (col[s] != -1) continue;
        ans = ans * 2 % MOD;
        col[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty() && ok) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (col[v] == -1) {
                    col[v] = col[u] ^ 1;
                    q.push(v);
                } else if (col[v] == col[u]) {
                    ok = false;
                    break;
                }
            }
        }
    }
    if (ok) cout << "SI " << ans << '\n';
    else cout << "NO\n";

    return 0;
}
