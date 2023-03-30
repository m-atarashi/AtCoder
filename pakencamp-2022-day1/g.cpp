#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1);
    P[1] = 0;
    for (int i = 2; i <= N; i++) cin >> P[i];
    int Q;
    cin >> Q;
    vector<vector<pair<int, int>>> query(N + 1);
    for (int i = 0; i < Q; i++) {
        int X, Y;
        cin >> X >> Y;
        query[Y].emplace_back(X, i);
    }
    vector<vector<int>> G(N + 1);
    for (int i = 1; i <= N; i++) G[P[i]].push_back(i);
    vector<int> anc(N + 1);
    vector<int> ans(Q);
    auto dfs = [&](auto dfs, int u) -> void {
        for (auto [x, i] : query[u]) ans[i] = anc[x];
        for (auto v : G[u]) {
            anc[u] = v;
            dfs(dfs, v);
        }
    };
    dfs(dfs, 0);
    for (auto v : ans) cout << v << '\n';
    return 0;
}