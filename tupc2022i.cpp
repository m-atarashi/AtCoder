#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
  int L, R;
  cin >> L >> R;
  // f(x): (L, R) = (1, x - 1)のときの答え
  // 求めるもの: f(R + 1) - f(L)
  // 1, 2, 3, 4, 5, 6, ..., x
  auto f = [](int x) -> mint {
    mint ans = 1LL << x;
    ans -= 1;
    return
  };
  cout << (f(R + 1) - f(L)).val() << endl;
  return 0;
}
