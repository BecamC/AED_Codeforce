#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        s += char('0' + x);
    }
    string fin = "123450";
    vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    map<string, int> d;
    queue<string> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        if (u == fin) break;
        int z = u.find('0');
        for (int v : adj[z]) {
            string t = u;
            swap(t[z], t[v]);
            if (!d.count(t)) {
                d[t] = d[u] + 1;
                q.push(t);
            }
        }
    }
    cout << (d.count(fin) ? d[fin] : -1) << '\n';

    return 0;
}
