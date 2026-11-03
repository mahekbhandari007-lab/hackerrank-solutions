// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-split-array-into-consecutive-subsequences/problem?isFullScreen=true
// Problem     Greedy Algorithm - Split Array into Consecutive Subsequences
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 09:00 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <unordered_map>

bool isPossible(const std::vector<int>& nums) {
    std::unordered_map<int, int> count;
    std::unordered_map<int, int> end;

    for (int num : nums) {
        count[num]++;
    }

    for (int x : nums) {
        if (count[x] == 0) {
            continue; // Already processed
        }

        // Option 1: Try to append x to an existing sequence ending at x - 1
        if (end[x - 1] > 0) {
            end[x - 1]--;
            end[x]++;
            count[x]--;
        }
        // Option 2: Try to create a new 3-element sequence [x, x + 1, x + 2]
        else if (count[x + 1] > 0 && count[x + 2] > 0) {
            count[x]--;
            count[x + 1]--;
            count[x + 2]--;
            end[x + 2]++;
        }
        // Neither option is valid
        else {
            return false;
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
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        if (isPossible(nums)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
    }

    return 0;
}
