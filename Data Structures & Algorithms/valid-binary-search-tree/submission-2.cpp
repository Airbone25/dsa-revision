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
    bool isValidBST(TreeNode* root) {
        queue<tuple<TreeNode*,long,long>> q;
        q.push({root,LONG_MIN,LONG_MAX});

        while(!q.empty()){
            auto [node,leftBound,rightBound] = q.front();
            q.pop();
            if(!(leftBound < node->val && rightBound > node->val)){
                    return false;
            }
            if(node->left){
                q.push({node->left,leftBound,node->val});
            }
            if(node->right){
                q.push({node->right,node->val,rightBound});
            }
        }

        return true;
    }
};
