#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

constexpr int M = 1e6;

int main() {
  ll N;
  cin >> N;

  vector<int> P;
  vector<bool> is_prime(M + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= M; i++) {
    if (!is_prime[i]) continue;
    P.push_back(i);
    for (ll j = 1LL * i * i; j <= M; j += i) {
      is_prime[j] = false;
    }
  }
  
  vector<int> cnt_p(M + 1, 0);
  for (int i = 2; i <= M; i++) cnt_p[i] += is_prime[i] + cnt_p[i - 1];

  ll ans = 0;
  for (int i = 0; i < (int)P.size(); i++) {
    ll a = P[i];
    if (a * a * a * a * a > N) break;
    for (int j = i + 1; j < (int)P.size(); j++) {
      ll b = P[j];
      if (a * a * b * b * b > N) break;
      ans += cnt_p[(int)sqrt(N / a / a / b)] - cnt_p[b];
    }
  }
  cout << ans << endl;
}