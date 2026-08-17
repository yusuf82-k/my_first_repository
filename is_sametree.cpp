#include <queue>

// Assuming the TreeNode struct is already defined by LeetCode
bool isSameTree(TreeNode* p, TreeNode* q) {
    // A queue to hold pairs of nodes that need to be compared
    std::queue<std::pair<TreeNode*, TreeNode*>> que;
    que.push({p, q});

    while (!que.empty()) {
        // Get the pair of nodes to compare
        TreeNode* first = que.front().first;
        TreeNode* second = que.front().second;
        que.pop();

        // 1. If both are null, this specific branch matches; move to the next
        if (first == nullptr && second == nullptr) continue;

        // 2. If only one is null OR the values don't match, they aren't the same
        if (first == nullptr || second == nullptr) return false;
        if (first->val != second->val) return false;

        // 3. Add the children in pairs to the queue for level-by-level comparison
        que.push({first->left, second->left});
        que.push({first->right, second->right});
    }

    return true;
}