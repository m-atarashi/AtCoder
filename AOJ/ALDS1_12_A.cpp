#include <bits/stdc++.h>
using namespace std;

struct dsu {
  private:
    int _n;
    std::vector<int> parent_or_size;

  public:
    dsu(int n) : _n(n), parent_or_size(n, -1) {}
    void merge(int a, int b) {
        int x = leader(a), y = leader(b);
        if (x == y) return;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
    }
    int leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
    bool same(int a, int b) {
        return leader(a) == leader(b);
    }
    int size(int a) {
        return -parent_or_size[leader(a)];
    }
};

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> Edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a != -1) {
                Edges.emplace_back(a, i, j);
            }
        }
    }
    sort(Edges.begin(), Edges.end());
    dsu uf(n);
    int sum = 0;
    for (auto [a, i, j] : Edges) {
        if (!uf.same(i, j)) {
            uf.merge(i, j);
            sum += a;
        }
    }
    cout << sum << endl;
    return 0;
}