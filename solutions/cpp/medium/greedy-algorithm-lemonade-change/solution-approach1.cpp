// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-lemonade-change/problem?isFullScreen=true
// Problem     Greedy Algorithm - Lemonade Change
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:51 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

bool lemonadeChange(const std::vector<int>& bills) {
    int five = 0;
    int ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five == 0) {
                return false;
            }
            five--;
            ten++;
        } else { // bill == 20
            // Greedily give one $10 and one $5 first to preserve $5 bills
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> bills(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> bills[i];
        }

        if (lemonadeChange(bills)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
    }

    return 0;
}
