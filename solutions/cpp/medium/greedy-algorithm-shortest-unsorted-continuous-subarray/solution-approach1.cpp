// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-shortest-unsorted-continuous-subarray/problem?isFullScreen=true
// Problem     Greedy Algorithm - Shortest Unsorted Continuous Subarray
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:53 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int findUnsortedSubarray(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (n <= 1) return 0;

    int right = -1;
    int max_val = INT_MIN;

    // Scan left to right to find the rightmost out-of-order element
    for (int i = 0; i < n; ++i) {
        max_val = std::max(max_val, nums[i]);
        if (nums[i] < max_val) {
            right = i;
        }
    }

    // If no out-of-order element found, the array is already sorted
    if (right == -1) return 0;

    int left = -1;
    int min_val = INT_MAX;

    // Scan right to left to find the leftmost out-of-order element
    for (int i = n - 1; i >= 0; --i) {
        min_val = std::min(min_val, nums[i]);
        if (nums[i] > min_val) {
            left = i;
        }
    }

    return right - left + 1;
}

int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        std::cout << findUnsortedSubarray(nums) << "\n";
    }

    return 0;
}
