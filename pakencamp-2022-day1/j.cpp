#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> G(N);
    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        if (A > B) swap(A, B);
        G[A].emplace_back(B, C);
    }
    int Q;
    cin >> Q;
}