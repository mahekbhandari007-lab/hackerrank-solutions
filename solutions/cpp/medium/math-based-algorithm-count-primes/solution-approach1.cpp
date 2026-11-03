// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-count-primes/problem?isFullScreen=true
// Problem     Math Based Algorithm - Count Primes 
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:10 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

int countPrimes(int n) {
    if (n <= 2) return 0;
    
    // Create a boolean array initialized to true
    std::vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    // Mark composite numbers using Sieve of Eratosthenes
    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Count remaining primes strictly less than n
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    if (std::cin >> n) {
        std::cout << countPrimes(n) << "\n";
    }
    
    return 0;
}
