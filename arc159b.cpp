#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
    ll A, B;
    cin >> A >> B;
    if (A < B) swap(A, B);

    auto func = [](ll a, ll b) -> ll {
        ll c = a - b;
        ll n = a % c;
        for (ll i = 2; i * i <= c; i++) {
            if (c % i == 0) {
                n = min(n, a % i);
                n = min(n, a % (c / i));
            }
        }
        if (!n) n = b;
        return n;
    };
    ll cnt = 0;
    auto dfs = [&](auto dfs, ll a, ll b) -> ll {
        cerr << a << " " << b << " " << cnt << endl;
        if (a == 0 || b == 0) return cnt;
        if (a == b) return ++cnt;
        ll g = gcd(a, b);
        if (g == 1) {
            ll n = func(a, b);
            cnt += n;
            dfs(dfs, a - n, b - n);
        } else {
            cnt++;
            dfs(dfs, a / g - 1, b / g - 1);
        }
        return cnt;
    };
    cout << dfs(dfs, A, B) << endl;
    return 0;
}