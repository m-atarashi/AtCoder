#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N, M, H, K;
  string S;
  cin >> N >> M >> H >> K >> S;

  set<pair<int, int>> item;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    item.insert({x, y});
  }

  int h = H;
  int cx = 0, cy = 0;
  bool is_ok = true;

  for (int i = 0; i < N; i++) {
    h--;
    if (S[i] == 'R') cx++;
    if (S[i] == 'L') cx--;
    if (S[i] == 'U') cy++;
    if (S[i] == 'D') cy--;

    if (h < 0) {
      is_ok = false;
      break;
    }

    if (item.count({cx, cy}) && h < K) {
      h = K;
      item.erase({cx, cy});
    }
  }
  cout << (is_ok ? "Yes" : "No") << endl;
}