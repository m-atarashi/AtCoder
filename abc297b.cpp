#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

bool solve() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> xy;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'B') xy.push_back(i);
    }
    if (xy[0] % 2 == xy[1] % 2) return false;
    xy.clear();
    int z;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') xy.push_back(i);
        if (S[i] == 'K') z = i;
    }
    return xy[0] < z && z < xy[1];
}

int main() {
    cout << (solve() ? "Yes" : "No") << endl;
}