// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/01-matrix-dynamic-programming/problem?isFullScreen=true
// Problem     01 Matrix - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:38 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <queue>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    if (!(std::cin >> m >> n) || m <= 0 || n <= 0) {
        return 0;
    }

    std::vector<std::vector<int>> mat(m, std::vector<int>(n));
    std::vector<std::vector<int>> dist(m, std::vector<int>(n, -1));
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> mat[i][j];
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Direction arrays for 4-directional traversal
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    // Multi-source BFS
    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // If neighbor is within bounds and unvisited
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    // Print output matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << dist[i][j] << (j + 1 == n ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
