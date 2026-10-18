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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int large = max(p->val, q->val);
        int small = min(p->val, q->val);

        while (root) {
            if (root->val > large) {
                root = root->left;
            } else if (root->val < small) {
                root = root->right;
            } else {
                return root;
            }
        }

        return NULL;
    }
};
