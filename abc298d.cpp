#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint998244353;

int main() {
  int Q;
  cin >> Q;
  mint S = 1;
  deque<int> d;
  d.push_back(1);
  for (;Q--;) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      d.push_back(x);
      S *= 10;
      S += x;
    }
    if (t == 2) {
      int top = d.front();
      d.pop_front();
      S -= top * mint(10).pow(d.size());
    }
    if (t == 3) {
      cout << S.val() << endl;
    }
  }
}