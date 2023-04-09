#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  priority_queue<ll> q;
  q.push(0);
  set<ll> used;
  used.insert(0);
  while (1) {
    ll v = q.top();
    q.pop();
    if (!K--) {
      cout << -v << endl;
      return 0;
    }
    for (int i = 0; i < N; i++) {
      ll nxt = v - A[i];
      if (used.count(nxt)) continue;
      q.push(nxt);
      used.insert(nxt);
    }
  }
}