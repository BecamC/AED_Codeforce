#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int imp = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] % 2) imp++;
    if (imp == 0) cout << "CIRCUITO\n";
    else if (imp == 2) cout << "CAMINO\n";
    else cout << "IMPOSIBLE\n";

    return 0;
}
