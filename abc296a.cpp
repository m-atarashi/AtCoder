#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  for (int i = 1; i < N; i++) {
    if (S[i - 1] == S[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}