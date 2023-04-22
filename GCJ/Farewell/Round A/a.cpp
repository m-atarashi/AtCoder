#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int j = 1; j <= T; j++) {
    vector<char> D(26);
    for (int i = 0; i < 26; i++) cin >> D[i];
    int N;
    cin >> N;
    set<string> res;
    for (int i = 0; i < N; i++) {
      string S;
      cin >> S;
      string T;
      for (auto s : S) {
        T += D[s - 'A'];
      }
      res.insert(T);
    }
    bool is_ok = (int)res.size() != N;
    printf("Case #%d: %s\n", j, (is_ok ? "YES" : "NO"));
  }
}