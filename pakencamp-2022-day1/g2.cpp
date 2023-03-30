#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

template <class T> ostream& operator<<(ostream& stream, vector<T>& vec) {
    for (int i = 0; i < (int)vec.size(); i++) {
        stream << vec[i] << " \n"[i == (int)vec.size() - 1];
    }
    return stream;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1, 0);
    P[1] = 1;
    for (int i = 2; i <= N; i++) cin >> P[i];

    vector<int> depth(N + 1, 0);
    depth[1] = 1;
    auto dfs = [&](auto dfs, int u) -> int {
        if (depth[u]) return depth[u];
        return depth[u] = dfs(dfs, P[u]) + 1;
    };
    vector doubling(31, vector<int>(N + 1, 0));
    doubling[0] = P;
    for (int i = 1; i < 31; i++) {
        for (int j = 1; j <= N; j++) {
            doubling[i][j] = doubling[i - 1][doubling[i - 1][j]];
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int X, Y;
        cin >> X >> Y;
        int d = dfs(dfs, Y) - dfs(dfs, X) - 1;
        for (int j = 0; j < 31; j++) {
            if (1 & d >> j) Y = doubling[j][Y];
        }
        cout << Y << '\n';
    }
    return 0;
}