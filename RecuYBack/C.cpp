#include <bits/stdc++.h>
using namespace std;

vector<string> tok;
int pos = 0;

long long eval()
{
    string s = tok[pos++];
    if (s == "+" || s == "-" || s == "*") {
        long long x = eval();
        long long y = eval();
        if (s == "+") return x + y;
        if (s == "-") return x - y;
        return x * y;
    }
    return stoll(s);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    tok.resize(m);
    for (auto &s : tok) cin >> s;
    cout << eval() << '\n';

    return 0;
}
