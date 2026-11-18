#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    ordered_set s;
    int id = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            s.insert({x, id++});
        } else if (t == 2) {
            int x;
            cin >> x;
            s.erase(s.lower_bound({x, INT_MIN}));
        } else {
            int l, r;
            cin >> l >> r;
            cout << s.order_of_key({r, INT_MAX}) - s.order_of_key({l, INT_MIN}) << '\n';
        }
    }

    return 0;
}
