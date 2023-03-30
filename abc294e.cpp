#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ll L;
  int N1, N2;
  cin >> L >> N1 >> N2;
  vector<pair<int, ll>> L1, L2;
  for (int i = 0; i < N1 + N2; i++) {
    int v;
    ll l;
    cin >> v >> l;
    (i < N1 ? L1 : L2).emplace_back(v, l);
  }
  int i = 0, j = 0;
  ll ans = 0, sum1 = 0, sum2 = 0;
  while (i < N1) {
    if (L1[i].first == L2[j].first) ans += min(sum1 + L1[i].second, sum2 + L2[j].second) - max(sum1, sum2);
    if (sum1 + L1[i].second <= sum2 + L2[j].second) sum1 += L1[i++].second;
    else sum2 += L2[j++].second;
  }
  cout << ans << endl;
  return 0;
}