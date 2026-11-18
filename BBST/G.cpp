#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    map<long long, long long> m;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            long long s, e;
            cin >> s >> e;
            auto it = m.lower_bound(s);
            bool ok = true;
            if (it != m.end() && it->first < e) ok = false;
            if (ok && it != m.begin() && prev(it)->second > s) ok = false;
            if (ok) {
                m[s] = e;
                cout << "SI\n";
            } else cout << "NO\n";
        } else if (op == 2) {
            long long s;
            cin >> s;
            m.erase(s);
        } else {
            long long t;
            cin >> t;
            auto it = m.upper_bound(t);
            if (it != m.begin() && prev(it)->second > t) cout << prev(it)->first << ' ' << prev(it)->second << '\n';
            else cout << "LIBRE\n";
        }
    }

    return 0;
}
