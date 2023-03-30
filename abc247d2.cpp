#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int Q;
  cin >> Q;
  int cur = 0, rem = 0;
  vector<int> X, C;
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, c;
      cin >> x >> c;
      X.push_back(x);
      C.push_back(c);
    }
    if (t == 2) {
      int c;
      cin >> c;
      ll ans = 0;
      while (c > 0) {
        ans += 1LL * X[cur] * C[cur];
        c -= C[cur++];
      }
      if (c < 0) {
        ans += 1LL * X[--cur] * c;
        C[cur] = -c;
      }
      cout << ans << endl;
    }
  }
  return 0;
}