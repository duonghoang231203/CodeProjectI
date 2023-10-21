#include <iostream>
#include <vector>

const int MOD = 1000000007;

int C(int k, int n) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    std::vector<std::vector<int> > dp(k + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[k][n];
}

int main() {
    int k, n;
    std::cin >> k >> n;
    std::cout << C(k, n) << std::endl;
    return 0;
}

