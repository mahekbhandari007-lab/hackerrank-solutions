// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-gas-station/problem?isFullScreen=true
// Problem     Greedy Algorithm - Gas Station
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:50 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>

int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {
    int n = static_cast<int>(gas.size());
    int total_tank = 0;
    int curr_tank = 0;
    int start_index = 0;

    for (int i = 0; i < n; ++i) {
        int net_gas = gas[i] - cost[i];
        total_tank += net_gas;
        curr_tank += net_gas;

        // If tank drops below 0, reset start candidate to next station
        if (curr_tank < 0) {
            start_index = i + 1;
            curr_tank = 0;
        }
    }

    return (total_tank >= 0) ? start_index : -1;
}

int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> gas(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> gas[i];
        }

        std::vector<int> cost(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> cost[i];
        }

        std::cout << canCompleteCircuit(gas, cost) << "\n";
    }

    return 0;
}
