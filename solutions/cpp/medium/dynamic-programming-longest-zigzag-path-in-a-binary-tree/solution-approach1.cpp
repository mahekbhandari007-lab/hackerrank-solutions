// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/dynamic-programming-longest-zigzag-path-in-a-binary-tree/problem?isFullScreen=true
// Problem     Dynamic Programming - Longest ZigZag Path in a Binary Tree
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-03, 08:15 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to construct binary tree from level-order traversal array
TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Process left child
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Process right child
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int max_zigzag = 0;

void dfs(TreeNode* node, int leftLen, int rightLen) {
    if (!node) return;

    max_zigzag = std::max({max_zigzag, leftLen, rightLen});

    // Moving left: extends rightLen or starts a new left path of length 1
    if (node->left) {
        dfs(node->left, rightLen + 1, 0);
    }

    // Moving right: extends leftLen or starts a new right path of length 1
    if (node->right) {
        dfs(node->right, 0, leftLen + 1);
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        std::vector<int> nodes(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nodes[i];
        }

        TreeNode* root = buildTree(nodes);
        
        // Start DFS with initial path lengths 0
        dfs(root, 0, 0);

        std::cout << max_zigzag << "\n";
    }

    return 0;
}
