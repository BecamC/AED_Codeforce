#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> N = {1, 2};
    while (N.back() <= (long long)1e18) N.push_back(N[N.size() - 1] + N[N.size() - 2] + 1);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int mn = 0;
        while (((1ULL << (mn + 1)) - 1) < (unsigned long long)n) mn++;
        int mx = 0;
        while (mx + 1 < (int)N.size() && N[mx + 1] <= n) mx++;
        cout << mn << ' ' << mx << '\n';
    }

    return 0;
}
