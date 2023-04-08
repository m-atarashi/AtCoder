#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    ll m = (ll)sqrt(M);
    ll ans = (m + 1) * (m + 1) + 1;
    // m ^ 2 <= M < (m + 1) ^ 2, a ^ 2 <= a * b < (m + 1) ^ 2, a < m + 1
    for (ll a = 1; a <= min(N, m + 1); a++) {
        ll b = (M + a - 1) / a;
        if (b <= N) ans = min(ans, a * b);
    }
    if (ans == (m + 1) * (m + 1) + 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}