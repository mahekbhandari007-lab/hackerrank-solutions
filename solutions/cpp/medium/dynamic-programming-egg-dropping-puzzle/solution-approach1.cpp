// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/dynamic-programming-egg-dropping-puzzle/problem?isFullScreen=true
// Problem     Dynamic Programming - Egg Dropping Puzzle
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:20 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

int superEggDrop(int k, int n) {
    // dp[i] stores the max floors we can test with 'i' eggs for the current move count
    std::vector<int> dp(k + 1, 0);
    int moves = 0;
    
    // Increment moves until we can check at least 'n' floors
    while (dp[k] < n) {
        moves++;
        // Update dp array backwards to use values from previous move step (m - 1)
        for (int i = k; i >= 1; --i) {
            dp[i] = dp[i] + dp[i - 1] + 1;
        }
    }
    
    return moves;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int k, n;
    if (std::cin >> k >> n) {
        std::cout << superEggDrop(k, n) << "\n";
    }
    
    return 0;
}
