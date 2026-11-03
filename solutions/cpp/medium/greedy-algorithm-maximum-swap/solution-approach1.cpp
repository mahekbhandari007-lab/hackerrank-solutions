// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-maximum-swap/problem?isFullScreen=true
// Problem     Greedy Algorithm - Maximum Swap
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:44 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int maximumSwap(int num) {
    std::string s = std::to_string(num);
    int n = static_cast<int>(s.length());

    // Store the last occurrence index of each digit ('0'-'9')
    std::vector<int> last(10, -1);
    for (int i = 0; i < n; ++i) {
        last[s[i] - '0'] = i;
    }

    // Traverse the string to find the first improvable digit
    for (int i = 0; i < n; ++i) {
        int current_digit = s[i] - '0';
        
        // Check for any larger digit appearing after index i
        for (int d = 9; d > current_digit; --d) {
            if (last[d] > i) {
                // Swap the current digit with its rightmost larger counterpart
                std::swap(s[i], s[last[d]]);
                return std::stoi(s);
            }
        }
    }

    return num; // Return original number if no beneficial swap exists
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num;
    if (std::cin >> num) {
        std::cout << maximumSwap(num) << "\n";
    }

    return 0;
}
