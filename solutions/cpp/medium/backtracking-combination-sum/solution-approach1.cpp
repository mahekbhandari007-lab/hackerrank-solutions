// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/backtracking-combination-sum/problem?isFullScreen=true
// Problem     Backtracking-combination sum
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 09:04 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>

void backtrack(int start_index, int target, const std::vector<int>& candidates, 
               std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start_index; i < static_cast<int>(candidates.size()); ++i) {
        // Pruning: Since candidates are sorted, if candidate[i] exceeds remaining target, break
        if (candidates[i] > target) {
            break;
        }

        current.push_back(candidates[i]);
        // Pass 'i' as start_index to allow unlimited reuse of the same element
        backtrack(i, target - candidates[i], candidates, current, result);
        current.pop_back(); // Backtrack
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> candidates[i];
        }

        int target;
        std::cin >> target;

        // Sort candidates for early pruning
        std::sort(candidates.begin(), candidates.end());

        std::vector<int> current;
        std::vector<std::vector<int>> result;

        backtrack(0, target, candidates, current, result);

        if (result.empty()) {
            std::cout << -1 << "\n";
        } else {
            for (const auto& comb : result) {
                for (size_t i = 0; i < comb.size(); ++i) {
                    std::cout << comb[i] << (i + 1 == comb.size() ? "" : " ");
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}
