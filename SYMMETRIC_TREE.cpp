#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Standard LeetCode Tree Node definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Procedural logic for Symmetry check
bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    queue<pair<TreeNode*, TreeNode*>> q;
    q.push({root->left, root->right});

    while (!q.empty()) {
        TreeNode* t1 = q.front().first;
        TreeNode* t2 = q.front().second;
        q.pop();

        if (!t1 && !t2) continue;
        if (!t1 || !t2 || t1->val != t2->val) return false;

        // The "Mirror" Pairing Strategy
        q.push({t1->left, t2->right}); // Outer pair
        q.push({t1->right, t2->left}); // Inner pair
    }
    return true;
}

int main() {
    /* Tree Structure:
             1
           /   \
          2     2
         / \   / \
        3   4 4   3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Call the function
    if (isSymmetric(root)) {
        cout << "The tree is Symmetric!" << endl;
    } else {
        cout << "The tree is NOT Symmetric." << endl;
    }

    return 0;
}