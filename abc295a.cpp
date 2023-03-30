#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string W;
    cin >> W;
    if (W == "and" || W == "not" || W == "that" || W == "the" || W == "you") {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}