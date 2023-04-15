#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
bool solve() {
  int N;
  cin >> N;
  vector A(N, vector<int>(N)), B(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> B[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    auto C = A;
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        C[j][k] = A[N - 1 - k][j];
      }
    }
    A = C;
    bool is_ok = true;
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (A[j][k] && !B[j][k]) {
          is_ok = false;
        }
      }
    }
    if (is_ok) {
      return true;
    }
  }
  return false;
}
int main() {
  cout << (solve() ? "Yes": "No") << endl;
}