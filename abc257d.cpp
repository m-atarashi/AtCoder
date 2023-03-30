#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  // ジャンプ台を頂点とみなしたときのグラフにおける全点間最短路問題を解く。
  // 辺の重みはS。Sの最小値が答え。経路長は累積和ではなく累積maxをとる。
  // ワーシャルフロイド法を用いると計算量はO(N ^ 3)。N <= 200なら十分間に合う。
  int N;
  cin >> N;
  vector<int> x(N), y(N), P(N);
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> P[i];
  vector dp(N, vector<ll>(N, 1LL << 60));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = (0LL + abs(x[i] - x[j]) + abs(y[i] - y[j]) + P[i] - 1) / P[i];
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
      }
    }
  }
  ll ans = 1LL << 60;
  for (int i = 0; i < N; i++) {
    ll tmp = 0;
    for (int j = 0; j < N; j++) tmp = max(tmp, dp[i][j]);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}