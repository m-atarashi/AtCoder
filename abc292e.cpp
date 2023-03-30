#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

struct P {
  int a, b, c;
  P(int a, int b, int c) : a(a), b(b), c(c) {}
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<set<int>> G(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].insert(v);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    queue<int> q;
    vector<bool> used(N, false);
    q.push(i);
    used[i] = true;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto u : G[v]) {
        if (!used[u]) {
          q.push(u);
          used[u] = true;
          if (!G[i].count(u)) ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}