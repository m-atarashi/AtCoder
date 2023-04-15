#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  bool is_ok = false;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'x') {
      cout << "No" << endl;
      return 0;
    }
    if (S[i] == 'o') {
      is_ok = true;
    }
  }
  cout << (is_ok ? "Yes": "No") << endl;
}