#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  ll ans = 0;
  int r = 1;
  for (int l = 0; l < N; l++) {
    while (r < N && a[r - 1] < a[r]) r++;
    ans += r - l;
    if (r == l + 1) r++;
  }
  cout << ans << endl;
  return 0;
}