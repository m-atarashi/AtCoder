#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main() {
  int N, M;
  cin >> N >> M;
  if (M == 0) {
    cout << "No" << endl;
    return 0;
  }
  dsu uf(N);
  vector<int> ce(N, 0);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    uf.merge(u, v);
    ce[uf.leader(u)]++;
  }
  bool ok = true;
  for (auto g : uf.groups()) ok &= g.size() == ce[uf.leader(g[0])];
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}