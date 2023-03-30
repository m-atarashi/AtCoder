#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main() {
  int N, P;
  cin >> N >> P;
  mint q = P * mint(100).inv();
  vector<vector<mint>> A = {{1 - q, q, 1}, {1, 0, 0}, {0, 0, 1}};
  vector<vector<mint>> AN = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  N--;
  auto dot = [](vector<vector<mint>> A, vector<vector<mint>> B)
      -> vector<vector<mint>> {
    vector<vector<mint>> tmp(A.size(), vector<mint>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < B[0].size(); j++) {
        for (int k = 0; k < A[0].size(); k++) {
          tmp[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    return tmp;
  };
  while (N > 0) {
    if (N & 1) AN = dot(AN, A);
    A = dot(A, A);
    N >>= 1;
  }
  cout << (AN[0][0] + AN[0][2]).val() << endl;
  return 0;
}