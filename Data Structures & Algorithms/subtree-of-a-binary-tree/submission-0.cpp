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
    bool isSame(TreeNode* p,TreeNode* q){
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        if(p->val != q->val){
            return false;
        }

        return isSame(p->left,q->left) && isSame(p->right,q->right);
    }
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            auto node = s.top();
            s.pop();

            if (node->val == subRoot->val) {
                if (isSame(node->left,subRoot->left) && isSame(node->right,subRoot->right)) {
                    return true;
                }
            }

            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }

        return false;
    }
};
