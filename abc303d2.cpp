#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  string S;
  cin >> S;
  int N = S.size();

  // cap がON/OFのときに c を押すのにかかる時間
  auto cost = [&X, &Y](char c, bool cap) -> ll {
    return ((c == 'A' ^ cap) ? Y : X);
  };

  // DP
  vector dp(N + 1, vector<ll>(2, 1e18));
  dp[0][0] = 0;
  dp[0][1] = Z;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost(S[i - 1], j));
      dp[i][j] = min(dp[i][j], dp[i - 1][1 - j] + cost(S[i - 1], 1 - j) + Z);
    }
  }
  cout << min(dp[N][0], dp[N][1]) << endl;
}