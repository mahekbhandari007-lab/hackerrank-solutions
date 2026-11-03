// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/minimum-path-sum-dynamic-programming/problem?isFullScreen=true
// Problem     Minimum Path Sum - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:42 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    if (!(std::cin >> m >> n) || m <= 0 || n <= 0) {
        return 0;
    }

    std::vector<std::vector<int>> grid(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grid[i][i == 0 ? j : j]; // grid populating
        }
    }

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    // Initialize first row
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Initialize first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Populate the DP table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    std::cout << dp[m - 1][n - 1] << "\n";

    return 0;
}
