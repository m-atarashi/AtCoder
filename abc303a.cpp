#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N;
  string S, T;
  cin >> N >> S >> T;
  bool is_ok = true;
  for (int i = 0; i < N; i++) {
    if (S[i] == T[i]) continue;
    if (S[i] == '1' && T[i] == 'l') continue;
    if (T[i] == '1' && S[i] == 'l') continue;
    if (S[i] == '0' && T[i] == 'o') continue;
    if (T[i] == '0' && S[i] == 'o') continue;
    is_ok = false;
  }
  cout << (is_ok ? "Yes" : "No") << endl;
}