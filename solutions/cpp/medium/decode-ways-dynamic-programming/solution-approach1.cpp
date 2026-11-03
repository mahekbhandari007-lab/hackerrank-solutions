// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/decode-ways-dynamic-programming/problem?isFullScreen=true
// Problem     Decode Ways - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:43 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
#include <vector>

int numDecodings(const std::string& s) {
    int n = static_cast<int>(s.length());
    if (n == 0 || s[0] == '0') {
        return 0;
    }

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: empty prefix
    dp[1] = 1; // Base case: first character non-zero

    for (int i = 2; i <= n; ++i) {
        // Single digit transition
        int one_digit = s[i - 1] - '0';
        if (one_digit >= 1 && one_digit <= 9) {
            dp[i] += dp[i - 1];
        }

        // Two digit transition
        int two_digits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (two_digits >= 10 && two_digits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (std::cin >> s) {
        std::cout << numDecodings(s) << "\n";
    }

    return 0;
}
