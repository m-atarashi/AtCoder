#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

using ll = long long;
using mint = modint998244353;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int cnt_0 = 0;
  for (auto a: A) if(!a) cnt_0++;
  vector binom(cnt_0 + 1, vector<mint>(cnt_0 + 1, 0));
  for (int i = 0; i <= cnt_0; i++) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
  }

  int cnt = N;
  mint ans = 0;
  for (int i = 1; i <= M; i++) {
    for (auto a: A) if (a == i - 1) cnt--;
    
    mint p = mint(M - i + 1) / M;
    vector<mint> pow_p(cnt_0 + 1, 1), pow_q(cnt_0 + 1, 1);
    for (int j = 1; j <= cnt_0; j++) {
      pow_p[j] = pow_p[j - 1] * p;
      pow_q[j] = pow_q[j - 1] * (1 - p);
    }
    for (int j = max(0, N - K + 1 - cnt); j <= cnt_0; j++) {
      ans += binom[cnt_0][j] * pow_p[j] * pow_q[cnt_0 - j];
    }
  }
  cout << ans.val() << endl;
}