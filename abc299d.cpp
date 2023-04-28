#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N;
  cin >> N;
  int l = 1, r = N;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    cout << "? " << mid << endl;
    bool b;
    cin >> b;
    if (b) r = mid;
    else l = mid;
  }
  cout << "! " << l << endl;
}