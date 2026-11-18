#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, x, y;
    cin >> A >> B >> x >> y;
    long long total = 0, in = 0;
    for (int a = 0; a <= A; a++)
        for (int b = 0; b <= B; b++) {
            int p = min(a, B - b), r = min(b, A - a);
            pair<int, int> t[6] = {{A, b}, {a, B}, {0, b}, {a, 0}, {a - p, b + p}, {a + r, b - r}};
            sort(t, t + 6);
            for (int i = 0; i < 6; i++) {
                if (i > 0 && t[i] == t[i - 1]) continue;
                if (t[i].first == a && t[i].second == b) continue;
                total++;
                if (t[i].first == x && t[i].second == y) in++;
            }
        }
    cout << total << ' ' << in << '\n';

    return 0;
}
