// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/coin-change-ii-dynamic-programming/problem?isFullScreen=true
// Problem     Coin Change II - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:37 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

int change(int amount, const std::vector<int>& coins) {
    // dp[j] stores the number of combinations to make amount j
    std::vector<int> dp(amount + 1, 0);
    
    // Base case: 1 way to make amount 0 (using no coins)
    dp[0] = 1;
    
    // Outer loop over coins ensures order does not matter
    for (int coin : coins) {
        for (int j = coin; j <= amount; ++j) {
            dp[j] += dp[j - coin];
        }
    }
    
    return dp[amount];
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int amount, n;
    if (std::cin >> amount >> n) {
        std::vector<int> coins(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> coins[i];
        }

        std::cout << change(amount, coins) << "\n";
    }

    return 0;
}
