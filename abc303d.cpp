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

  // 連長圧縮
  vector<pair<char, int>> RLE;
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (S[i - 1] == S[i]) {
      cnt++;
    } else {
      RLE.emplace_back(S[i - 1], cnt);
      cnt = 1;
    }
  }
  if (cnt) RLE.emplace_back(S.back(), cnt);
  int M = RLE.size();

  // cap がON/OFのときに c を押すのにかかる時間
  auto cost = [&X, &Y](char c, bool cap) -> ll {
    return ((c == 'A' ^ cap) ? Y : X);
  };

  // DP
  vector dp(M + 1, vector<ll>(2, 1e18));
  dp[0][0] = 0;
  dp[0][1] = Z;

  for (int i = 1; i <= M; i++) {
    for (int j = 0; j < 2; j++) {
      char c = RLE[i - 1].first;
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + RLE[i - 1].second * cost(c, j));
      dp[i][j] = min(dp[i][j], dp[i - 1][1 - j] + RLE[i - 1].second * cost(c, 1 - j) + Z);
    }
  }
  cout << min(dp[M][0], dp[M][1]) << endl;
}