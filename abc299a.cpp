#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  string T;
  for (int i = 0; i < N; i++) {
    if (S[i] == '|' || S[i] == '*') T.push_back(S[i]);
  }
  if (T == "|*|") cout << "in";
  else cout << "out";
}