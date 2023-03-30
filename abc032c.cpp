#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  if (find(s.begin(), s.end(), 0) != s.end()) {
    cout << n << endl;
    return 0;
  }
  ll p = 1;
  int ans = 0;
  int r = 0;
  for (int l = 0; l < n; l++) {
    while (r < n && p * s[r] <= k) {
      p *= s[r];
      r++;
    }
    ans = max(ans, r - l);
    if (r == l) r++;
    else p /= s[l];
  }
  cout << ans << endl;
  return 0;
}