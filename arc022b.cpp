#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  int ans = 0;
  int r = 0;
  vector<bool> used(N, false);
  for (int l = 0; l < N; l++) {
    while (r < N && !used[A[r]]) {
      used[A[r]] = true;
      r++;
    }
    ans = max(ans, r - l);
    used[A[l]] = false;
    if (l == r) r++;
  }
  cout << ans << endl;
  return 0;
}