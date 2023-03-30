#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
  string S;
  cin >> S;
  vector<int> cnt(1 << 10, 0);
  cnt[0]++;
  int now = 0;
  for (int i = 0; i < S.size(); i++) {
    now ^= 1 << (S[i] - '0');
    cnt[now]++;
  }
  ll ans = 0;
  for (auto c: cnt) ans += 1LL * c * (c - 1) / 2;
  cout << ans << endl;
}