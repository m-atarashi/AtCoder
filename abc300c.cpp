#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int i = 0; i < H; i++) cin >> C[i];
  int N = min(H, W);
  vector<int> S(N + 1, 0);
  for (int a = 0; a < H; a++) {
    for (int b = 0; b < W; b++) {
      if (C[a][b] != '#') continue;
      int cnt = 0;
      for (int i = 1; i <= N; i++) {
        if (!(a + i < H && a - i >= 0 && b + i < W && b - i >= 0)) break;
        if (C[a + i][b + i] == '#' && C[a + i][b - i] == '#' && C[a - i][b - i] == '#' && C[a - i][b + i] == '#') {
          cnt++;
        } else {
          break;
        }
      }
      S[cnt]++;
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << S[i] << ' ';
  }
}