// K以上の値の要素は正しい場所にないとダメ
#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  if (K > N) {
    cout << "Yes" << endl;
    return 0;
  }
  vector<int> P(N + 1, 0);
  for (int i = 1; i <= N; i++) cin >> P[i];
  bool ok = true;
  for (int i = K; i <= N; i++) {
    if (P[i] != i) ok = false;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
