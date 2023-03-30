#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll H, W;
  int N;
  cin >> H >> W >> N;
  set<pair<int, int>> g;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g.insert({x, y});
  }
  int ans = 0;
  set<pair<int, int>> used;
  auto f = [&](int i, int j) -> int {
    if (i < 0 || j < 0) return 0;
    if (used.count({i, j})) return 0;
    used.insert({i, j});
    int res = 0;
    res += g.count({i, j});
    res += g.count({i, j + 1});
    res += g.count({i + 1, j});
    res += g.count({i + 1, j + 1});
    return res % 2;
  };
  for (auto [x, y]: g) {
    ans += f(x, y) + f(x - 1, y) + f(x, y - 1) + f(x - 1, y - 1);
  }
  cout << ans << endl;
  return 0;
}