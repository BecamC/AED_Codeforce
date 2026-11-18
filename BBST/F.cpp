#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    set<long long> s;
    while (q--) {
        int op;
        long long x;
        cin >> op >> x;
        if (op == 1) s.insert(x);
        else if (op == 2) s.erase(x);
        else {
            auto it = s.lower_bound(x);
            long long ans;
            if (it == s.end()) ans = *prev(it);
            else if (it == s.begin()) ans = *it;
            else {
                long long d = *it, a = *prev(it);
                ans = (x - a <= d - x) ? a : d;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
