#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  vector deg(N, 0);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }

  queue<int> q;
  vector S(N, 0);

  // 端の星を探す
  for (int i = 0; i < N; i++) {
    if (deg[i] != 1) continue;
    S[i] = -1;
    int s = G[i][0];
    if (S[s]) continue;
    q.push(s);
    S[s] = 1;
  }

  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (auto u : G[s]) {
      if (S[u]) continue;
      S[u] = -1;
      if (G[u].size() == 1) continue;

      // 橋を探す
      int v = G[u][0] != s ? G[u][0] : G[u][1];
      if (S[v]) continue;
      S[v] = -1;

      // 隣の星を探す
      int t = G[v][0] != u ? G[v][0] : G[v][1];
      if (S[t]) continue;
      q.push(t);
      S[t] = 1;
    }
  }

  vector<int> L;
  for (int i = 0; i < N; i++) {
    if (S[i] == 1) {
      L.push_back(G[i].size());
    }
  }
  sort(L.begin(), L.end());
  for (auto l : L) cout << l << ' ';
  cout << endl;
}