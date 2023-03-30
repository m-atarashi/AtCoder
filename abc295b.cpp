#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main() {
  int R, C;
  cin >> R >> C;
  vector<string> B(R);
  for (int i = 0; i < R; i++) cin >> B[i];
  vector<string> D = B;
  for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
    if (!isdigit(B[i][j])) continue;
    for (int k = 0; k < R; k++) for (int l = 0; l < C; l++) {
      if (abs(i - k) + abs(j - l) <= B[i][j] - '0') {
        D[k][l] = '.';
      }
    }
  }
  for (int i = 0; i < R; i++) cout << D[i] << endl;
  return 0;
}