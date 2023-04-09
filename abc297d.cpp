#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  ll A, B;
  cin >> A >> B;
  ll cnt = 0;
  if (A == B) {
    cout << 0 << endl;
    return 0;
  }
  while (A) {
    if (A < B) swap(A, B);
    cnt += A / B;
    A %= B;
  }
  cout << cnt - 1 << endl;
}