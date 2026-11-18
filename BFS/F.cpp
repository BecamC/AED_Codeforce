#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int ini = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '1') ini |= 1 << (i * m + j);
    }
    int dx[] = {0, 1, -1, 0, 0}, dy[] = {0, 0, 0, 1, -1};
    vector<int> mask(n * m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 5; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m) mask[i * m + j] |= 1 << (x * m + y);
            }
    vector<int> d(1 << (n * m), -1);
    queue<int> q;
    d[ini] = 0;
    q.push(ini);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        if (s == 0) break;
        for (int c = 0; c < n * m; c++) {
            int t = s ^ mask[c];
            if (d[t] == -1) {
                d[t] = d[s] + 1;
                q.push(t);
            }
        }
    }
    cout << d[0] << '\n';

    return 0;
}
