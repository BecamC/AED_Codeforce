#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    unordered_map<int, int> cnt;
    cnt.reserve(1 << 20);
    set<pair<int, int>> s;
    while (q--) {
        int op;
        cin >> op;
        if (op == 3) {
            auto it = s.begin();
            cout << it->second << ' ' << -it->first << '\n';
            continue;
        }
        int x;
        cin >> x;
        int &c = cnt[x];
        if (c) s.erase({-c, x});
        c += (op == 1) ? 1 : -1;
        if (c) s.insert({-c, x});
    }

    return 0;
}
