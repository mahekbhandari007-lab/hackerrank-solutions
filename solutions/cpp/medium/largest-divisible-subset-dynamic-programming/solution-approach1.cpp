// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/largest-divisible-subset-dynamic-programming/problem?isFullScreen=true
// Problem     Largest Divisible Subset - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 09:13 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if (dp[i] > dp[maxIndex])
            maxIndex = i;
    }

    vector<long long> result;

    while (maxIndex != -1)
    {
        result.push_back(nums[maxIndex]);
        maxIndex = parent[maxIndex];
    }

    reverse(result.begin(), result.end());

    for (long long x : result)
        cout << x << " ";

    return 0;
}

