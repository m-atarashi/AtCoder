#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
  int N;
  cin >> N;
  map<int, int> cnt;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    cnt[A]++;
  }
  ll ans = 0;
  for (auto [a, c]: cnt) ans += c / 2;
  cout << ans << endl;
  return 0;
}