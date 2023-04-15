#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N;
  cin >> N;
  int Q;
  cin >> Q;
  vector<multiset<int>> box(N + 1);
  vector<set<int>> place(2e5 + 1);
  for (;Q--;) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, j;
      cin >> i >> j;
      box[j].insert(i);
      place[i].insert(j);
    }
    if (t == 2) {
      int i;
      cin >> i;
      for (auto a: box[i]) {
        cout << a << ' ';
      }
      cout << endl;
    }
    if (t == 3) {
      int i;
      cin >> i;
      for (auto a: place[i]) {
        cout << a << ' ';
      }
      cout << endl;
    }
  }
}