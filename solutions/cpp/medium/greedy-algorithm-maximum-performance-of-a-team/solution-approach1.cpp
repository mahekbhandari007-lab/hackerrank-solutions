// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-maximum-performance-of-a-team/problem?isFullScreen=true
// Problem     Greedy Algorithm - Maximum Performance of a Team
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:49 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Engineer {
    int speed;
    int efficiency;
};

bool compareEngineers(const Engineer& a, const Engineer& b) {
    return a.efficiency > b.efficiency; // Sort in descending order of efficiency
}

int maxPerformance(int n, int k, const std::vector<int>& speed, const std::vector<int>& efficiency) {
    std::vector<Engineer> eng(n);
    for (int i = 0; i < n; ++i) {
        eng[i] = {speed[i], efficiency[i]};
    }

    // 1. Sort engineers by efficiency in descending order
    std::sort(eng.begin(), eng.end(), compareEngineers);

    // 2. Min-heap to maintain top k speeds
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    
    long long speed_sum = 0;
    long long max_perf = 0;

    // 3. Iterate through engineers, maintaining at most k max speeds
    for (int i = 0; i < n; ++i) {
        min_heap.push(eng[i].speed);
        speed_sum += eng[i].speed;

        if (static_cast<int>(min_heap.size()) > k) {
            speed_sum -= min_heap.top();
            min_heap.pop();
        }

        // eng[i].efficiency is guaranteed to be the minimum in the current team
        long long current_perf = speed_sum * eng[i].efficiency;
        max_perf = std::max(max_perf, current_perf);
    }

    const int MOD = 1e9 + 7;
    return static_cast<int>(max_perf % MOD);
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> speed(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> speed[i];
        }

        std::vector<int> efficiency(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> efficiency[i];
        }

        std::cout << maxPerformance(n, k, speed, efficiency) << "\n";
    }

    return 0;
}
