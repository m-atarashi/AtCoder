#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  if (N == 1) cout << 0 << endl;
  else if (M == 1) cout << -1 << endl;
  else cout << (N - 1 + M - 1 - 1) / (M - 1) << endl;
}