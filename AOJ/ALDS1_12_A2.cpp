#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector G(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }
    priority_queue<pair<int, int>> q;
    q.emplace(0, 0);
    vector<bool> visited(n, false);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int u, a;
        while (true) {
            auto [v, b] = q.top();
            q.pop();
            u = v, a = b;
            if (!visited[u]) break;
        }
        visited[u] = true;
        sum += a;
        for (int j = 0; j < n; j++) {
            if (G[u][j] != -1 && !visited[j]) {
                q.emplace(u, j);
            }
        }
    }
    cout << sum << endl;
    return 0;
}