// 0  1 0 1 1 10 0 0
// -1 -1 -1 -1 -1 -1 -1

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  int M, K;
  cin >> N >> M >> K;
  vector<ll> a(M + 2);
  vector<int> b(M + 2);
  for (int i = 1; i <= M; i++) cin >> a[i] >> b[i];
  a[0] = a[1] - 1;
  a[M + 1] = N + 1;
  ll ans = 0, c = 0;
  for (int i = 1; i <= M; i++) {
    c = b[i] - 1 + max(0LL, c - (a[i] - a[i - 1] - 1));
    ll y = c - K + 1;
    if (y > 0) ans += min(y, a[i + 1] - a[i]);
    printf("a[i];%d c;%ld ans:%ld\n", a[i],c,ans);
  }
  cout << ans << endl;
  return 0;
}