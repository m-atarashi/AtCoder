#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int Q;
  cin >> Q;
  deque<pair<int, int>> d;
  for (;Q--;) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, c;
      cin >> x >> c;
      d.emplace_back(x, c);
    }
    if (t == 2) {
      int c;
      cin >> c;
      ll ans = 0;
      while (c) {
        auto [x, cc] = d.front();
        d.pop_front();
        ans += 1LL * x * cc;
        c -= cc;
        if (c < 0) {
          d.emplace_front(x, -c);
          ans += 1LL * x * c;
          c = 0;
        }
      }
      cout << ans << endl;
    }
  }
}