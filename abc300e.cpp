#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint998244353;

int main() {
  ll N;
  cin >> N;
  vector<int> pf(6, 0);
  for (auto i : {2, 3, 5}) {
    while (N % i == 0) {
      N /= i;
      pf[i]++;
    }
  }
  if (N != 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<mint> frac(64, 1);
  for (int i = 2; i < 64; i++) frac[i] = frac[i - 1] * i;
  mint ans = 0;
  for (int n6 = 0; n6 <= min(pf[2], pf[3]); n6++) {
    for (int n4 = 0; n4 <= (pf[2] - n6) / 2; n4++) {
      int n2 = pf[2] - 2 * n4 - n6;
      int n3 = pf[3] - n6;
      int n5 = pf[5];
      int n = n2 + n3 + n4 + n5 + n6;
      ans += mint(5).inv().pow(n) * frac[n] / frac[n2] / frac[n3] / frac[n4] / frac[n5] / frac[n6];
    }
  }
  cout << ans.val() << endl;
}