#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector A(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    int Q;
    cin >> Q;
    for (; Q--;) {
        ll s, t;
        cin >> s >> t;
        s--, t--;
        s %= N;
        t %= N;
        queue<ll> q;
        vector<int> dist(N, -1);
        q.push(s);
        while (!q.empty()) {
            ll v = q.front();
            q.pop();
            int d = dist[v];
            for (int i = 0; i < N; i++) {
                if (!A[v][i]) continue;
                if (dist[i] == -1) {
                    dist[i] = d + 1;
                    q.push(i);
                }
            }
        }
        if (dist[t] == -1) {
            cout << -1 << endl;
        } else {
            cout << dist[t] + 1 << endl;
        }
    }
    return 0;
}