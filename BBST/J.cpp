#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    ordered_set s;
    while (q--) {
        int t, y;
        cin >> t >> y;
        if (t == 1) s.insert(y);
        else if (t == 2) s.erase(y);
        else cout << *s.find_by_order(y - 1) << '\n';
    }

    return 0;
}
