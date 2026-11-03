// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-minimum-deletions-to-make-array-divisible/problem?isFullScreen=true
// Problem     Math Based Algorithm - Minimum Deletions to Make Array Divisible
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:11 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate GCD of two numbers
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minDeletions(std::vector<int>& nums, const std::vector<int>& numsDivide) {
    // 1. Calculate the GCD of all elements in numsDivide
    long long g = numsDivide[0];
    for (size_t i = 1; i < numsDivide.size(); ++i) {
        g = gcd(g, numsDivide[i]);
    }

    // 2. Sort nums to iterate from smallest to largest
    std::sort(nums.begin(), nums.end());

    // 3. Find the smallest element in nums that divides g
    for (size_t i = 0; i < nums.size(); ++i) {
        if (g % nums[i] == 0) {
            return static_cast<int>(i); // Number of elements deleted before nums[i]
        }
    }

    // 4. If no element can divide all of numsDivide
    return -1;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    if (std::cin >> n >> m) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        std::vector<int> numsDivide(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> numsDivide[i];
        }

        std::cout << minDeletions(nums, numsDivide) << "\n";
    }

    return 0;
}
