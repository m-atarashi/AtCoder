#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  auto f = [](int n) -> ll {
    ll cnt = 0;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        cnt++;
        if (n / i != i) cnt++;
      }
    }
    return cnt;
  };
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    ans += f(i) * f(N - i);
  }
  cout << ans << endl;
  return 0;
}