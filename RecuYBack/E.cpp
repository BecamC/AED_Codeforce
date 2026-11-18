#include <bits/stdc++.h>
using namespace std;

int n;
long long cnt = 0;
vector<string> g;
bool col[10], d1[20], d2[20];

void bt(int f)
{
    if (f == n) {
        cnt++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (g[f][c] == '#' || col[c] || d1[f + c] || d2[f - c + n - 1]) continue;
        col[c] = d1[f + c] = d2[f - c + n - 1] = true;
        bt(f + 1);
        col[c] = d1[f + c] = d2[f - c + n - 1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    for (auto &s : g) cin >> s;
    bt(0);
    cout << cnt << '\n';

    return 0;
}
