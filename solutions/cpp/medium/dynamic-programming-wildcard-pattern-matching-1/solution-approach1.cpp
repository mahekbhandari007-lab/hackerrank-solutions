// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/dynamic-programming-wildcard-pattern-matching-1/problem?isFullScreen=true
// Problem     Dynamic Programming - Wildcard Pattern Matching 1
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:13 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>

bool isMatch(const std::string& s, const std::string& p) {
    int sIdx = 0, pIdx = 0;
    int starIdx = -1, matchIdx = 0;
    
    int sLen = static_cast<int>(s.length());
    int pLen = static_cast<int>(p.length());
    
    while (sIdx < sLen) {
        // 1. Current characters match or pattern has '?'
        if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
            sIdx++;
            pIdx++;
        }
        // 2. Pattern has '*'
        else if (pIdx < pLen && p[pIdx] == '*') {
            starIdx = pIdx;
            matchIdx = sIdx;
            pIdx++; // Try matching 0 characters first
        }
        // 3. Mismatch occurred, but we encountered a '*' earlier
        else if (starIdx != -1) {
            pIdx = starIdx + 1;
            matchIdx++;
            sIdx = matchIdx; // Extend '*' to match one more character
        }
        // 4. Mismatch with no prior '*'
        else {
            return false;
        }
    }
    
    // Check for remaining trailing '*' in pattern
    while (pIdx < pLen && p[pIdx] == '*') {
        pIdx++;
    }
    
    return pIdx == pLen;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s, p;
    // Reading string inputs (handles empty string edge cases)
    std::cin >> s >> p;
    
    if (isMatch(s, p)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    
    return 0;
}
