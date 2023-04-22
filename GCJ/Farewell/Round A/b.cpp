#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool solve() {
  int M, R, N;
  cin >> M >> R >> N;
  bool is_ok = true;
  vector<int> X(N);
  for (int i = 0; i < N; i++) cin >> X[i];
  if (X.front() - R > 0) return 0;
  if (X.back() + R < M) return 0;

  for (int i = 1; i < N; i++) {
    if (X[i] - X[i - 1] > 2LL * R) return 0;
  }
  int cnt = 0;
  int cx = 0;
  auto l = X.begin();
  while (cx < M) {
    auto it = upper_bound(l, X.end(), cx + 2LL * R);
    if (it == X.end()) break;
    it--;
    cx = *it;
    l = it;
    cnt++;
  }
  return cnt;
}

int main() {
  int T;
  cin >> T;
  for (int j = 1; j <= T; j++) {
    int ans = solve();
    if (ans) {
      printf("Case #%d: %d\n", j, ans);
    } else {
      printf("Case #%d: %s\n", j, "IMPOSSIBLE");
    }
  }
}