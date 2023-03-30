#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> cnt(N, 0);
  for (; Q--;) {
    int c, x;
    cin >> c >> x;
    x--;
    if (c == 3) cout << (cnt[x] >= 2 ? "Yes" : "No") << endl;
    else cnt[x] += c;
  }
  return 0;
}