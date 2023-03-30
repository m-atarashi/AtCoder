#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    vector<pair<int, int>> C(N + M);
    for (int i = 0; i < N; i++) C[i] = {A[i], i};
    for (int i = 0; i < M; i++) C[N + i] = {B[i], i + N};
    sort(C.begin(), C.end());

    for (int i = 0; i < N + M; i++) if (C[i].second < N) cout << i + 1 << ' ';
    cout << endl;
    return 0;
}