#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint998244353;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    mint ans = 0;
    mint sum = 0;
    vector<mint> frac(H * W + 1, 1);
    for (int i = 1; i < H * W; i++) {
        frac[i] = frac[i - 1] * i;
    }
    auto comb = [&frac](int n, int k) -> mint {
        if (n < 0) return 0;
        if (k < 0) return 0;
        if (n < k) return 0;
        return frac[n] * frac[k].inv() * frac[n - k].inv();
    };
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (i * j >= K) {
                mint cnt = 0;
                cnt += comb(i * j - 4, K - 4);
                cnt += comb(i * j - 4, K - 2) * 2;
                cnt += comb(i * j - 4, K - 3) * 4;
                if (i > 2)
                    cnt += comb(i * j - 5, K - 3) * (i - 2) * 2;
                if (j > 2)
                    cnt += comb(i * j - 5, K - 3) * (j - 2) * 2;
                if (i > 2 && j > 2) {
                    cnt += comb(i * j - 6, K - 3) * (i - 2) * (j - 2) * 4;
                    cnt += comb(i * j - 8, K - 4) * (i - 2) * (i - 2) * (j - 2) * (j - 2);
                }
                cnt *= mint(H - i + 1) * mint(W - j + 1);
                sum += cnt;
                ans += i * j * cnt;
            }
        }
    }
    cout << (ans * sum.inv()).val() << endl;
}