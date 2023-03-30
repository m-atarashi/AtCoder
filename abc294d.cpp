#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main() {
  int N, Q;
  cin >> N >> Q;
  set<int> called, uncalled;
  for (int i = 1; i <= N; i++) uncalled.insert(i);
  for (; Q--;) {
    int t;
    cin >> t;
    if (t == 1) {
      called.insert(*uncalled.begin());
      uncalled.erase(*uncalled.begin());
    }
    if (t == 2) {
      int x;
      cin >> x;
      called.erase(x);
    }
    if (t == 3) {
      cout << *called.begin() << endl;
    }
  }
  cout << endl;
  return 0;
}