#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N, D;
  cin >> N >> D;
  vector T(N, 0);
  for (int i = 0; i < N; i++) cin >> T[i];
  for (int i = 0; i < N - 1; i++) {
    if (T[i + 1] - T[i] <= D) {
      cout << T[i + 1] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}