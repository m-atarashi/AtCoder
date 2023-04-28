#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> C(N), R(N);
  for (int i = 0; i < N; i++) cin >> C[i];
  for (int i = 0; i < N; i++) cin >> R[i];

  int ans = -1;
  int cm = -1;
  for (int i = 0; i < N; i++) {
    if (C[i] == T) {
      if (cm < R[i]) {
        ans = i;
        cm = R[i];
      }
    }
  }
  if (ans != -1) {
    cout << ans + 1 << endl;
    return 0;
  }

  ans = 0;
  for (int i = 0; i < N; i++) {
    if (C[i] == C[0]) {
      if (R[ans] < R[i]) ans = i;
    }
  }
  cout << ans + 1 << endl;
}