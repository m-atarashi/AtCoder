#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N), P(N);
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> P[i];

  // Sを二分探索する。始点を全探索する。
  ll l = 0, r = 4e9;
  while (l + 1 < r) {
    ll S = (l + r) / 2;
    vector<vector<int>> G(N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (P[i] * S >= 0LL + abs(x[i] - x[j]) + abs(y[i] - y[j])) {
          G[i].push_back(j);
        }
      }
    }
    vector<bool> used(N, false);
    vector<int> topo;
    auto dfs = [&](auto dfs, int u) -> void {
      if (used[u]) return; 
      used[u] = true;
      for (auto v: G[u]) dfs(dfs, v);
      topo.push_back(u);
    };
    for (int i = 0; i < N; i++) if (!used[i]) dfs(dfs, i);
    bool ok = true;
    for (auto b: used) ok &= b;
    if (ok) r = S;
    else l = S;   
  }
  cout << r << endl;
  return 0;
}