#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  set<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.insert(a);
  }
  for (auto it = A.begin(); it != A.end(); it++) {
    if (A.find(X + *it) != A.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}