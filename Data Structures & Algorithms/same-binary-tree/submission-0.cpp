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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*,TreeNode*>> s;
        s.push({p,q});
        while(!s.empty()){
            auto [i,j] = s.top();
            s.pop();

            if(!i && !j){
                continue;
            }else if(!i || !j || i->val != j->val){
                return false;
            }

            s.push({i->right,j->right});
            s.push({i->left,j->left});
        }

        return true;
    }
};
