// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-check-if-it-is-a-good-array/problem?isFullScreen=true
// Problem     Math Based Algorithm - Check If It Is a Good Array
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:09 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

// Helper function to calculate GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        long long current_gcd = 0;
        
        for (int i = 0; i < n; ++i) {
            long long x;
            std::cin >> x;
            current_gcd = gcd(current_gcd, x);
            
            // Optimization: If GCD reaches 1 early, we know the answer is True
            if (current_gcd == 1) {
                // Continue consuming input to clear stream if needed, or exit
            }
        }

        if (current_gcd == 1) {
            std::cout << "True\n";
        } else {
            std::cout << "False\n";
        }
    }

    return 0;
}
