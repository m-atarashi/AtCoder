#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int cnt = 0;
  int cntmax = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'o') cnt++;
    else {
      cntmax = max(cntmax, cnt);
      cnt = 0;
    }
  }
  cntmax = max(cntmax, cnt);
  if (!cntmax || cntmax == N) cout << -1 << endl;
  else cout << cntmax << endl;
}