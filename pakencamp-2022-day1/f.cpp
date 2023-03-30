#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
    int N, M, D;
    cin >> N >> M >> D;
    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    vector A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> A[i][j];
    }
    ll ans = 0;
    for (int i = 0; i < 1 << N; i++) {
        ll d = 0;
        vector<int> max_A(M, 0);
        for (int j = 0; j < N; j++) {
            if (!(1 & i >> j)) continue;
            d += L[j];
            for (int k = 0; k < M; k++) max_A[k] = max(max_A[k], A[j][k]);
        }
        ll tmp = 0;
        for (auto a: max_A) tmp += a;
        if (d <= D) ans = max(ans, tmp);
    }
    if (ans) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}