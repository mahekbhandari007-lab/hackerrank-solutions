// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/number-of-longest-increasing-subsequences-dynamic-programming/problem?isFullScreen=true
// Problem     Number of Longest Increasing Subsequences - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:40 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>

int findNumberOfLIS(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (n <= 1) return n;

    std::vector<int> length(n, 1);
    std::vector<int> count(n, 1);

    int max_len = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    count[i] = count[j];
                } else if (length[j] + 1 == length[i]) {
                    count[i] += count[j];
                }
            }
        }
        max_len = std::max(max_len, length[i]);
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (length[i] == max_len) {
            result += count[i];
        }
    }

    return result;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        std::cout << findNumberOfLIS(nums) << "\n";
    }

    return 0;
}
