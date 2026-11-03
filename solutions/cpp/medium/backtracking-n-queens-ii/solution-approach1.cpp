// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/backtracking-n-queens-ii/problem?isFullScreen=true
// Problem     Backtracking-N-Queens II
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 09:03 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

void solveNQueens(int r, int n, std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2, int& count) {
    if (r == n) {
        count++;
        return;
    }

    for (int c = 0; c < n; ++c) {
        int d1 = r - c + n - 1;
        int d2 = r + c;

        if (!cols[c] && !diag1[d1] && !diag2[d2]) {
            // Place queen
            cols[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solveNQueens(r + 1, n, cols, diag1, diag2, count);

            // Backtrack
            cols[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
}

int totalNQueens(int n) {
    int count = 0;
    std::vector<bool> cols(n, false);
    std::vector<bool> diag1(2 * n - 1, false);
    std::vector<bool> diag2(2 * n - 1, false);

    solveNQueens(0, n, cols, diag1, diag2, count);
    return count;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n && n > 0) {
        std::cout << totalNQueens(n) << "\n";
    }

    return 0;
}
