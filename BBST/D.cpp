#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int K[MAXN], L[MAXN], R[MAXN], H[MAXN], cnt = 0;

int alt(int v)
{
    return v ? H[v] : -1;
}

void upd(int v)
{
    H[v] = max(alt(L[v]), alt(R[v])) + 1;
}

int fb(int v)
{
    return alt(L[v]) - alt(R[v]);
}

int rotIzq(int x)
{
    int y = R[x];
    R[x] = L[y];
    L[y] = x;
    upd(x);
    upd(y);
    return y;
}

int rotDer(int x)
{
    int y = L[x];
    L[x] = R[y];
    R[y] = x;
    upd(x);
    upd(y);
    return y;
}

int balancear(int v)
{
    upd(v);
    int b = fb(v);
    if (b > 1) {
        if (fb(L[v]) < 0) L[v] = rotIzq(L[v]);
        return rotDer(v);
    }
    if (b < -1) {
        if (fb(R[v]) > 0) R[v] = rotDer(R[v]);
        return rotIzq(v);
    }
    return v;
}

int insertar(int v, int k)
{
    if (!v) {
        cnt++;
        K[cnt] = k;
        L[cnt] = R[cnt] = 0;
        H[cnt] = 0;
        return cnt;
    }
    if (k < K[v]) L[v] = insertar(L[v], k);
    else R[v] = insertar(R[v], k);
    return balancear(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int raiz = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        raiz = insertar(raiz, a);
        cout << H[raiz] << ' ' << K[raiz] << '\n';
    }

    return 0;
}
