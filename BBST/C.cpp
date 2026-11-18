#include <bits/stdc++.h>
using namespace std;

int n, q, raiz = 1;
vector<int> L, R, P;

void rotIzq(int x)
{
    int y = R[x];
    R[x] = L[y];
    if (L[y]) P[L[y]] = x;
    P[y] = P[x];
    if (!P[x]) raiz = y;
    else if (L[P[x]] == x) L[P[x]] = y;
    else R[P[x]] = y;
    L[y] = x;
    P[x] = y;
}

void rotDer(int x)
{
    int y = L[x];
    L[x] = R[y];
    if (R[y]) P[R[y]] = x;
    P[y] = P[x];
    if (!P[x]) raiz = y;
    else if (L[P[x]] == x) L[P[x]] = y;
    else R[P[x]] = y;
    R[y] = x;
    P[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    L.assign(n + 1, 0);
    R.assign(n + 1, 0);
    P.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
        if (L[i]) P[L[i]] = i;
        if (R[i]) P[R[i]] = i;
    }

    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'I') rotIzq(x);
        else rotDer(x);
    }

    cout << raiz << '\n';
    for (int i = 1; i <= n; i++) cout << L[i] << ' ' << R[i] << '\n';

    return 0;
}
