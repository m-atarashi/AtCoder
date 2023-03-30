#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  mint ans = 1;
  for (int i = 0; i < (N + 1) / 2; i++) {
    if (S[i] != '?' && S[N - 1 - i] != '?' && S[i] != S[N - 1 - i]) ans *= 0;
    if (S[i] == '?' && S[N - 1 - i] == '?') ans *= 26;
  }
  cout << ans.val() << endl;
  return 0;
}