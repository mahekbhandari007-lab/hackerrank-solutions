// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-minimum-number-of-moves-to-make-palindrome/problem?isFullScreen=true
// Problem     Greedy Algorithm - Minimum Number of Moves to Make Palindrome
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:55 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
#include <utility>

int minMovesToMakePalindrome(std::string s) {
    int n = static_cast<int>(s.length());
    int moves = 0;
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            // Search from right towards left to find matching character s[left]
            int k = right;
            while (k > left && s[k] != s[left]) {
                k--;
            }

            if (k == left) {
                // s[left] is the unique middle character in an odd-length palindrome.
                // Move it one position to the right towards the middle.
                std::swap(s[left], s[left + 1]);
                moves++;
            } else {
                // Move the matching character at k to position right via adjacent swaps
                while (k < right) {
                    std::swap(s[k], s[k + 1]);
                    moves++;
                    k++;
                }
                left++;
                right--;
            }
        }
    }

    return moves;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (std::cin >> s) {
        std::cout << minMovesToMakePalindrome(s) << "\n";
    }

    return 0;
}
