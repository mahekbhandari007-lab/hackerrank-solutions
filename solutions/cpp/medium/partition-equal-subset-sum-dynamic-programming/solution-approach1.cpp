// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/partition-equal-subset-sum-dynamic-programming/problem?isFullScreen=true
// Problem     Partition Equal Subset Sum - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:34 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <numeric>

bool canPartition(const std::vector<int>& nums) {
    int total_sum = 0;
    for (int num : nums) {
        total_sum += num;
    }

    // An odd total sum cannot be divided into two equal integer sums
    if (total_sum % 2 != 0) {
        return false;
    }

    int target = total_sum / 2;
    std::vector<bool> dp(target + 1, false);
    dp[0] = true; // Base case: sum of 0 is always possible

    for (int num : nums) {
        // Update dp array backwards to avoid using the same element multiple times
        for (int j = target; j >= num; --j) {
            if (dp[j - num]) {
                dp[j] = true;
            }
        }
        // Early exit optimization
        if (dp[target]) {
            return true;
        }
    }

    return dp[target];
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

        if (canPartition(nums)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
    }

    return 0;
}
