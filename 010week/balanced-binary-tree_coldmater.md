# balanced-binary-tree

https://leetcode.com/problems/balanced-binary-tree

# 첫 번째 시도

## 아이디어

## 소스코드

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isB = true;
    int dfs (TreeNode* n) {
        if (!n) {
            // cout << "null\n";
            return 0;
        }
        // left
        int ld = dfs(n->left);

        // right
        int rd = dfs(n->right);
        int d = max(ld, rd) + 1;
        int dd = abs(ld - rd);
        if (dd >= 2) isB = false;
        // cout << n->val << ", depth: " << d << ", dd: " << dd <<  "\n";
        return d;
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        // if (root == 0) return false;
        // cout << root->val;
        return isB;
    }
}
```
