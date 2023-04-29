#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  ll N;
  cin >> N;
  int M = (int)sqrt(N / (2 * 2 * 3)) + 1;
  vector<bool> is_prime(M + 1, true);
  for (ll i = 2; i * i <= M; i++) {
    if (!is_prime[i]) continue;
    for (ll j = i * i; j <= M; j += i) {
      is_prime[j] = false;
    }
  }
  ll cnt = 0;
  vector<int> P;
  for (int i = 2; i <= M; i++) {
    if (is_prime[i]) P.push_back(i);
  }
  for (int i = 0; i < (int)P.size() && 1LL * P[i] * P[i] * P[i] * P[i] * P[i] <= N; i++) {
    for (int j = i + 1; j < (int)P.size() && 1LL * P[i] * P[i] * P[j] * P[j] * P[j] <= N; j++) {
      for (int l = j + 1; l < (int)P.size() && 1LL * P[i] * P[i] * P[j] * P[l] * P[l] <= N; l++) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}