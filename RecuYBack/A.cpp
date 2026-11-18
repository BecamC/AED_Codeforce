#include <bits/stdc++.h>
using namespace std;

int n;
long long S, cnt = 0;
vector<long long> a;

void bt(int i, long long suma)
{
    if (suma > S) return;
    if (i == n) {
        if (suma == S) cnt++;
        return;
    }
    bt(i + 1, suma + a[i]);
    bt(i + 1, suma);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> S;
    a.resize(n);
    for (auto &x : a) cin >> x;
    bt(0, 0);
    cout << cnt << '\n';

    return 0;
}
