#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto &a : adj) sort(a.begin(), a.end());
    while (q--) {
        int u, v;
        cin >> u >> v;
        const vector<int> &A = adj[u], &B = adj[v];
        size_t i = 0, j = 0;
        int c = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] < B[j]) i++;
            else if (A[i] > B[j]) j++;
            else {
                c++;
                i++;
                j++;
            }
        }
        cout << c << '\n';
    }

    return 0;
}
