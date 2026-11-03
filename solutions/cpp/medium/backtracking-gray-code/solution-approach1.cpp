// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/backtracking-gray-code/problem?isFullScreen=true
// Problem     Backtracking-Gray Code
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 09:05 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

std::vector<int> grayCode(int n) {
    int total_elements = 1 << n; // 2^n elements
    std::vector<int> result(total_elements);

    for (int i = 0; i < total_elements; ++i) {
        result[i] = i ^ (i >> 1);
    }

    return result;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n && n >= 1) {
        std::vector<int> result = grayCode(n);

        int total_elements = static_cast<int>(result.size());
        for (int i = 0; i < total_elements; ++i) {
            std::cout << result[i] << (i + 1 == total_elements ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
