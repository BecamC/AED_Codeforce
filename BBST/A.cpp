#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> k(n + 1);
        vector<int> l(n + 1), r(n + 1);
        for (int i = 1; i <= n; i++) cin >> k[i] >> l[i] >> r[i];

        vector<long long> lo(n + 1), hi(n + 1);
        vector<int> h(n + 1, 0), orden;
        orden.reserve(n);
        orden.push_back(1);
        lo[1] = LLONG_MIN;
        hi[1] = LLONG_MAX;
        bool bst = true;
        for (size_t i = 0; i < orden.size(); i++) {
            int v = orden[i];
            if (k[v] <= lo[v] || k[v] >= hi[v]) bst = false;
            if (l[v]) {
                lo[l[v]] = lo[v];
                hi[l[v]] = k[v];
                orden.push_back(l[v]);
            }
            if (r[v]) {
                lo[r[v]] = k[v];
                hi[r[v]] = hi[v];
                orden.push_back(r[v]);
            }
        }

        if (!bst) {
            cout << "NINGUNO\n";
            continue;
        }

        bool avl = true;
        for (int i = (int)orden.size() - 1; i >= 0; i--) {
            int v = orden[i];
            int hl = l[v] ? h[l[v]] : -1;
            int hr = r[v] ? h[r[v]] : -1;
            if (abs(hl - hr) > 1) avl = false;
            h[v] = max(hl, hr) + 1;
        }

        cout << (avl ? "AVL" : "BST") << '\n';
    }

    return 0;
}
