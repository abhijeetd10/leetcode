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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int val;
        while(!q.empty()) {
            TreeNode* curr  = q.front();
            q.pop();
            val = curr->val;
            if(curr->right) {
                q.push(curr->right);
            }
            if(curr->left) {
                q.push(curr->left);
            }
        }
        return val;
    }
};
