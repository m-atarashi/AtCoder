#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int N, K;
  cin >> N >> K;
  vector<bool> A(N, false);
  for (int i = 0; i < N && K; i += 3) {
    A[i] = true;
    K--;
    if (K && i + 1 < N) {
      A[i + 1] = true;
      K--;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    if (K && !A[i]) {
      A[i] = true;
      K--;
    }
  }
  for (int i = 0; i < N; i++) {
    if (A[i]) cout << i + 1 << ' ';
  }
  cout << endl;
  return 0;
}