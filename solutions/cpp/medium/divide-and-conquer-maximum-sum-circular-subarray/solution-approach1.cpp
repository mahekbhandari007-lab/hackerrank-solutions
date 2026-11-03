// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/divide-and-conquer-maximum-sum-circular-subarray/problem?isFullScreen=true
// Problem     Divide and Conquer - Maximum Sum Circular Subarray
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:02 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int maxSubarraySumCircular(const std::vector<int>& nums) {
    int total_sum = 0;
    
    int max_kadane = nums[0];
    int current_max = 0;
    
    int min_kadane = nums[0];
    int current_min = 0;
    
    for (int x : nums) {
        // Standard Kadane's for Maximum Subarray Sum
        current_max = std::max(x, current_max + x);
        max_kadane = std::max(max_kadane, current_max);
        
        // Standard Kadane's for Minimum Subarray Sum
        current_min = std::min(x, current_min + x);
        min_kadane = std::min(min_kadane, current_min);
        
        total_sum += x;
    }
    
    // If all numbers are negative, max_kadane is the maximum single element.
    // total_sum - min_kadane would equal 0 (an empty subarray), which is invalid.
    if (max_kadane < 0) {
        return max_kadane;
    }
    
    return std::max(max_kadane, total_sum - min_kadane);
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }
        
        std::cout << maxSubarraySumCircular(nums) << "\n";
    }
    
    return 0;
}
