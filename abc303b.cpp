#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  set<pair<int, int>> friendly;
  for (int i = 0; i < M; i++) {
    int prev;
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      if (j > 0) {
        int b = prev, aa = a;
        if (aa < b) swap(aa, b);
        friendly.insert({aa, b});
      }
      prev = a;
    }
  }
  cout << N * (N - 1) / 2 - friendly.size() << endl;
}