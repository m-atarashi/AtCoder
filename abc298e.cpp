#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main() {
  int N, A, B, P, Q;
  cin >> N >> A >> B >> P >> Q;
  A--, B--;
  mint p_inv = mint(P).inv();
  mint q_inv = mint(Q).inv();

  vector dp(N, vector(N, vector<mint>(2, 0)));
  dp[0][A][0] = 1;
  dp[0][B][1] = 1;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      for (int k = 1; k <= P; k++) {
        dp[i + 1][min(j + k, N - 1)][0] += dp[i][j][0] * p_inv;
      }
      for (int k = 1; k <= Q; k++) {
        dp[i + 1][min(j + k, N - 1)][1] += dp[i][j][1] * q_inv;
      }
    }
  }

  mint ans = A == N - 1;
  for (int i = 1; i < N; i++) {
    mint sum = 0;
    for (int j = 0; j < N - 1; j++) {
      sum += dp[i- 1][j][1];
    }
    ans += dp[i][N - 1][0] * sum;
  }
  cout << ans.val() << endl;
}