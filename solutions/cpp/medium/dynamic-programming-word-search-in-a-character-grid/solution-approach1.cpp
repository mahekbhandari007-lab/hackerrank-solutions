// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/dynamic-programming-word-search-in-a-character-grid/problem?isFullScreen=true
// Problem     Backtracking - Word Search in a Character Grid
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 09:01 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <string>

bool dfs(std::vector<std::vector<char>>& board, int r, int c, const std::string& word, int index, int m, int n) {
    if (index == static_cast<int>(word.length())) {
        return true;
    }

    // Boundary check and character match check
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]) {
        return false;
    }

    // Mark current cell as visited
    char temp = board[r][c];
    board[r][c] = '#';

    // Explore 4 directions
    static const int dr[] = {-1, 1, 0, 0};
    static const int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        if (dfs(board, r + dr[i], c + dc[i], word, index + 1, m, n)) {
            return true;
        }
    }

    // Backtrack: restore original character
    board[r][c] = temp;
    return false;
}

bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
    int m = static_cast<int>(board.size());
    if (m == 0) return false;
    int n = static_cast<int>(board[0].size());

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == word[0] && dfs(board, i, j, word, 0, m, n)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    if (std::cin >> m >> n && m > 0 && n > 0) {
        std::vector<std::vector<char>> board(m, std::vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> board[i][j];
            }
        }

        std::string word;
        std::cin >> word;

        if (exist(board, word)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
    }

    return 0;
}
