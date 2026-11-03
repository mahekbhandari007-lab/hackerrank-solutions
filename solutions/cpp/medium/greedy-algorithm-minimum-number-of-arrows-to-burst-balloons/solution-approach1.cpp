// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-minimum-number-of-arrows-to-burst-balloons/problem?isFullScreen=true
// Problem     Greedy Algorithm - Minimum Number of Arrows to Burst Balloons
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:46 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>

struct Balloon {
    long long start;
    long long end;
};

bool compareBalloons(const Balloon& a, const Balloon& b) {
    return a.end < b.end;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n) || n <= 0) {
        std::cout << 0 << "\n";
        return 0;
    }

    std::vector<Balloon> balloons(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> balloons[i].start >> balloons[i].end;
    }

    // 1. Sort balloons by their ending points in ascending order
    std::sort(balloons.begin(), balloons.end(), compareBalloons);

    // 2. Greedily place arrows
    int arrows = 1;
    long long current_end = balloons[0].end;

    for (int i = 1; i < n; ++i) {
        // If the current balloon starts after the last arrow position, shoot a new arrow
        if (balloons[i].start > current_end) {
            arrows++;
            current_end = balloons[i].end;
        }
    }

    std::cout << arrows << "\n";

    return 0;
}
