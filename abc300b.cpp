#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H), B(H);
  for (int i = 0; i < H; i++) cin >> A[i];
  for (int i = 0; i < H; i++) cin >> B[i];
  for (int s = 0; s < H; s++) {
    for (int t = 0; t < W; t++) {
      if (A == B) {
        cout << "Yes" << endl;
        return 0;
      }
      string tmp = "";
      for (int i = 0; i < H; i++) tmp.push_back(A[i][W - 1]);
      for (int i = W - 1; i > 0; i--) {
        for (int j = 0; j < H; j++) A[j][i] = A[j][i - 1];
      }
      for (int i = 0; i < H; i++) A[i][0] = tmp[i];
    }
    auto tmp = A[H - 1];
    for (int i = H - 1; i > 0; i--) A[i] = A[i - 1];
    A[0] = tmp;
  }
  cout << "No" << endl;
  return 0;
}