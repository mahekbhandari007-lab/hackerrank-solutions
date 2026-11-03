// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-rectangle-area/problem?isFullScreen=true
// Problem     Math Based Algorithm - Rectangle Area
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:07 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <algorithm>

int computeArea(int ax1, int ay1, int ax2, int ay2, 
                int bx1, int by1, int bx2, int by2) {
    // 1. Calculate individual areas
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);
    
    // 2. Find boundaries of the intersection rectangle
    int overlap_x1 = std::max(ax1, bx1);
    int overlap_x2 = std::min(ax2, bx2);
    int overlap_y1 = std::max(ay1, by1);
    int overlap_y2 = std::min(ay2, by2);
    
    // 3. Calculate overlap width and height
    int overlap_width = std::max(0, overlap_x2 - overlap_x1);
    int overlap_height = std::max(0, overlap_y2 - overlap_y1);
    
    int overlap_area = overlap_width * overlap_height;
    
    // 4. Return total unique area covered
    return area1 + area2 - overlap_area;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    
    if (std::cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2) {
        std::cout << computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << "\n";
    }
    
    return 0;
}
