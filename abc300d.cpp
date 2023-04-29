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
  if (M >= 0) is_prime[0] = false;
  if (M >= 1) is_prime[1] = false;
  for (ll i = 2; i * i <= M; i++) {
    if (!is_prime[i]) continue;
    for (ll j = i * i; j <= M; j += i) {
      is_prime[j] = false;
    }
  }
  ll cnt = 0;
  vector<int> P;
  for (int i = 0; i <= M; i++) {
    if (is_prime[i]) P.push_back(i);
  }

  for (int i = 0; i < (int)P.size() - 2; i++) {
    int a = P[i];
    if (1LL * a * a * a * a * a > N) break;
    for (int j = i + 1; j < (int)P.size() - 1; j++) {
      int b = P[j];
      if (1LL * a * a * b * b * b > N) break;
      for (int l = j + 1; l < (int)P.size(); l++) {
        int c = P[l];
        if (1LL * a * a * b * c * c <= N) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
}