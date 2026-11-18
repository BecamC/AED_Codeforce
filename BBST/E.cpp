#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
int K[MAXN], L[MAXN], R[MAXN], H[MAXN], cnt = 0;
long long rots = 0;

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
    rots++;
    int y = R[x];
    R[x] = L[y];
    L[y] = x;
    upd(x);
    upd(y);
    return y;
}

int rotDer(int x)
{
    rots++;
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

int eliminar(int v, int k)
{
    if (k < K[v]) L[v] = eliminar(L[v], k);
    else if (k > K[v]) R[v] = eliminar(R[v], k);
    else {
        if (!L[v]) return R[v];
        if (!R[v]) return L[v];
        int s = R[v];
        while (L[s]) s = L[s];
        K[v] = K[s];
        R[v] = eliminar(R[v], K[s]);
    }
    return balancear(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    int raiz = 0;
    while (q--) {
        int op, x;
        cin >> op >> x;
        rots = 0;
        if (op == 1) raiz = insertar(raiz, x);
        else raiz = eliminar(raiz, x);
        cout << rots << ' ' << alt(raiz) << '\n';
    }

    return 0;
}
