#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      if (a) cout << (char)('A' + a - 1);
      else cout << '.';
    }
    cout << endl;
  }
  return 0;
}