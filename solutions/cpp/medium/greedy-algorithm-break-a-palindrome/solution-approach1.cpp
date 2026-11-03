// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-break-a-palindrome/problem?isFullScreen=true
// Problem     Greedy Algorithm - Break a Palindrome
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:52 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>

std::string breakPalindrome(std::string palindrome) {
    int n = static_cast<int>(palindrome.length());
    
    // Impossible if the length is 1
    if (n <= 1) {
        return "";
    }

    // Look at the first half of the string
    for (int i = 0; i < n / 2; ++i) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }

    // If all characters in the first half are 'a', change the last character to 'b'
    palindrome[n - 1] = 'b';
    return palindrome;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string palindrome;
    if (std::cin >> palindrome) {
        std::cout << breakPalindrome(palindrome) << "\n";
    }

    return 0;
}
