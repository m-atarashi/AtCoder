#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    set<pair<ll, int>> s;
    for (int i = 0; i < N; i++) s.insert({A[i], i});

    ll cum = 0;
    for (; Q--;) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1) {
            s.erase(s.find({A[x], x}));
            A[x] += y;
            s.insert({A[x], x});
            cum += y;
            vector<int> died;
            auto it = s.begin();
            while (it != s.end() || it->first > cum) {
                died.push_back(it->second);
                s.erase(it++);
            }
            sort(died.begin(), died.end());
            cout << died.size();
            for (auto i : died) cout << ' ' << i + 1;
            cout << endl;
        }
        if (t == 2) {
            s.erase(s.find({A[x], x}));
            A[x] -= y;
            if (A[x] <= cum) cout << 1 << ' ' << x + 1 << endl;
            else {
                cout << '0' << endl;
                s.insert({A[x], x});
            }
        }
    }
}