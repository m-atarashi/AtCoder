#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P, Q;
    cin >> N >> P >> Q;
    vector<int> A(P), B(P);
    for (int i = 0; i < P; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < Q; i++) {
        int C, D;
        cin >> C >> D;
        C--, D--;
        G[D].push_back(C);
    }
    vector<int> X(N, 0);
    for (int i = 0; i < N; i++) {
        if (G[i].empty()) continue;
        vector<int> Y;
        for (auto u : G[i]) Y.push_back(X[u]);
        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());
        X[i] = Y.back() + 1;
        for (int j = 0; j < (int)Y.size(); j++) {
            if (Y[j] != j) {
                X[i] = j;
                break;
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < P; i++) {
        ok &= X[A[i]] == X[B[i]];
    }
    if (ok) {
        for (auto x : X) cout << x + 1 << ' ';
    } else {
        cout << -1 << endl;
    }
}