#include <bits/stdc++.h>
using namespace std;

int n;
string cur;

void bt(int ab, int ce)
{
    if (ab == n && ce == n) {
        cout << cur << '\n';
        return;
    }
    if (ab < n) {
        cur.push_back('(');
        bt(ab + 1, ce);
        cur.pop_back();
    }
    if (ce < ab) {
        cur.push_back(')');
        bt(ab, ce + 1);
        cur.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    bt(0, 0);

    return 0;
}
