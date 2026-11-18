#include <bits/stdc++.h>
using namespace std;

vector<string> g(9);
int fil[9], co[9], caja[9];

int box(int i, int j)
{
    return (i / 3) * 3 + j / 3;
}

bool bt()
{
    int bi = -1, bj = -1, best = 10, bm = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (g[i][j] == '.') {
                int m = ~(fil[i] | co[j] | caja[box(i, j)]) & 0x3FE;
                int c = __builtin_popcount(m);
                if (c < best) {
                    best = c;
                    bi = i;
                    bj = j;
                    bm = m;
                }
            }
    if (bi == -1) return true;
    if (best == 0) return false;
    for (int d = 1; d <= 9; d++) {
        if (!(bm >> d & 1)) continue;
        int b = 1 << d;
        g[bi][bj] = '0' + d;
        fil[bi] |= b;
        co[bj] |= b;
        caja[box(bi, bj)] |= b;
        if (bt()) return true;
        fil[bi] ^= b;
        co[bj] ^= b;
        caja[box(bi, bj)] ^= b;
        g[bi][bj] = '.';
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        cin >> g[i];
        for (int j = 0; j < 9; j++)
            if (g[i][j] != '.') {
                int b = 1 << (g[i][j] - '0');
                fil[i] |= b;
                co[j] |= b;
                caja[box(i, j)] |= b;
            }
    }
    bt();
    for (auto &s : g) cout << s << '\n';

    return 0;
}
