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
        int t, x;
        cin >> t >> x;
        if (t == 1) s.insert(x);
        else cout << s.order_of_key(x) << '\n';
    }

    return 0;
}
