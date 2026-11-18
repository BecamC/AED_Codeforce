#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int a, int b, int c)
{
    if (n == 0) return;
    hanoi(n - 1, a, c, b);
    cout << n << ' ' << a << ' ' << b << '\n';
    hanoi(n - 1, c, b, a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);

    return 0;
}
