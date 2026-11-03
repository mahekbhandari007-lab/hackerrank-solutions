// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-increasing-triplet-subsequence/problem?isFullScreen=true
// Problem     Greedy Algorithm - Increasing Triplet Subsequence
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:47 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <climits>

bool increasingTriplet(const std::vector<int>& nums) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int num : nums) {
        if (num <= first) {
            first = num;
        } else if (num <= second) {
            second = num;
        } else {
            // Found num > second > first
            return true;
        }
    }

    return false;
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

        if (increasingTriplet(nums)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
    }

    return 0;
}
