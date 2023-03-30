#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = 0;
  int sum = 0, xsum = 0;
  int r = 0;
  for (int l = 0; l < N; l++) {
    while (r < N && (xsum ^ A[r]) == (sum + A[r])) {
      xsum ^= A[r];
      sum += A[r];
      r++;
    }
    ans += r - l;
    xsum ^= A[l];
    sum -= A[l];
    if (r == l) r++;
  }
  cout << ans << endl;
  return 0;
}