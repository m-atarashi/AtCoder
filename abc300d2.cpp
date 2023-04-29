#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  ll N;
  cin >> N;

  int M = (int)sqrt(N / 2 / 2 / 3);
  vector<int> P;
  vector<bool> is_prime((int)sqrt(N) + 1, true);
  for (int i = 2; i <= M; i++) {
    if (!is_prime[i]) continue;
    P.push_back(i);
    for (int j = i * 2; j <= M; j += i) is_prime[j] = false;
  }

  int cnt = 0;
  for (int i = 0; i < (int)P.size(); i++) {
    ll a = P[i];
    if (a * a * a * a * a > N) break;
    for (int j = i + 1; j < (int)P.size(); j++) {
      ll b = P[j];
      if (a * a * b * b * b > N) break;
      auto it = upper_bound(P.begin() + j + 1, P.end(), sqrt(N / a / a / b));
      cnt += it - (P.begin() + j + 1);
    }
  }
  cout << cnt << endl;
}