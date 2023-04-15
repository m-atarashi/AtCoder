#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

vector dx = {1, 0, -1, 0};
vector dy = {0, 1, 0, -1};

int main() {
  int R, C;
  cin >> R >> C;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  vector<string> c(R + 2, string(C + 2, '#'));
  for (int i = 0; i < R; i++) {
    string cc;
    cin >> cc;
    c[i + 1] = '#' + cc + '#';
  }

  queue<pair<int, int>> q;
  vector dist(R + 2, vector(C + 2, 1e8));
  q.emplace(sy, sx);
  dist[sy][sx] = 0;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (c[ny][nx] == '#' || dist[ny][nx] != 1e8) continue;
      dist[ny][nx] = dist[y][x] + 1;
      q.push({ny, nx});
    }
  }
  cout << dist[gy][gx] << endl;
}