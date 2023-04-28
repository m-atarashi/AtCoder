#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int K;
  cin >> K;
  vector<int> P(K), D(K);
  for (int i = 0; i < K; i++) {
    int p, d;
    cin >> p >> d;
    p--;
    P[i] = p;
    D[i] = d;
  }
  vector color(N, true);
  vector dist(N, vector<int>(N, -1));
  for (int i = 0; i < K; i++) {
    queue<int> q;
    q.push(P[i]);
    dist[i][P[i]] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto u : G[v]) {
        if (dist[i][u] != -1) continue;
        dist[i][u] = dist[i][v] + 1;
        q.push(u);
      }
    }
    for (int j = 0; j < N; j++) {
      if (dist[i][j] < D[i]) {
        color[j] = false;
      }
    }
  }
  bool is_ok = true;
  for (int i = 0; i < K; i++) {
    bool tmp = false;
    for (int j = 0; j < N; j++) {
      if (dist[i][j] == D[i]) {
        tmp |= color[j];
      }
    }
    is_ok &= tmp;
  }
  if (is_ok) {
    cout << "Yes\n";
    for (auto c: color) cout << c;
    cout << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}