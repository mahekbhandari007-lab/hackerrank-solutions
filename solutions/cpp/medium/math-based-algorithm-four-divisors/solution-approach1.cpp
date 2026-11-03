// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-four-divisors/problem?isFullScreen=true
// Problem     Math Based Algorithm - Four Divisors
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:04 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <cmath>

// Helper function to calculate sum of divisors if count is exactly 4
int getFourDivisorsSum(int num) {
    int count = 0;
    int sum = 0;
    int last_divisor = 0;
    
    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            count += 1;
            sum += i;
            last_divisor = i;
            
            // If the divisors are distinct (i != num / i)
            if (i * i != num) {
                count += 1;
                sum += num / i;
            }
            
            // Early exit if more than 4 divisors
            if (count > 4) {
                return 0;
            }
        }
    }
    
    return (count == 4) ? sum : 0;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    if (std::cin >> n) {
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            total_sum += getFourDivisorsSum(num);
        }
        
        std::cout << total_sum << "\n";
    }
    
    return 0;
}
