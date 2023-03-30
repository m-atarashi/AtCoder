#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (char c : S) cout << char(c + ('A' - 'a'));
  cout << endl;
  return 0;
}