// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/backtracking-restore-ip-addresses/problem?isFullScreen=true
// Problem     Backtracking- Restore IP Addresses
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 09:02 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <string>

bool isValidPart(const std::string& segment) {
    int len = static_cast<int>(segment.length());
    if (len == 0 || len > 3) return false;
    
    // Check for leading zero
    if (len > 1 && segment[0] == '0') return false;
    
    // Check range 0-255
    int val = std::stoi(segment);
    return val >= 0 && val <= 255;
}

void restoreIpAddressesHelper(const std::string& s, int start_index, std::vector<std::string>& current_parts, std::vector<std::string>& result) {
    int n = static_cast<int>(s.length());
    int parts_count = static_cast<int>(current_parts.size());

    // Base case: 4 valid parts collected
    if (parts_count == 4) {
        if (start_index == n) {
            std::string ip = current_parts[0] + "." + current_parts[1] + "." + current_parts[2] + "." + current_parts[3];
            result.push_back(ip);
        }
        return;
    }

    // Pruning: check if remaining characters can fit in remaining needed parts
    int remaining_chars = n - start_index;
    int remaining_parts = 4 - parts_count;
    if (remaining_chars < remaining_parts || remaining_chars > remaining_parts * 3) {
        return;
    }

    // Try segment lengths of 1, 2, and 3
    for (int len = 1; len <= 3 && start_index + len <= n; ++len) {
        std::string segment = s.substr(start_index, len);
        if (isValidPart(segment)) {
            current_parts.push_back(segment);
            restoreIpAddressesHelper(s, start_index + len, current_parts, result);
            current_parts.pop_back(); // Backtrack
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> current_parts;
        std::vector<std::string> result;

        restoreIpAddressesHelper(s, 0, current_parts, result);

        if (result.empty()) {
            std::cout << -1 << "\n";
        } else {
            for (const std::string& ip : result) {
                std::cout << ip << "\n";
            }
        }
    }

    return 0;
}
