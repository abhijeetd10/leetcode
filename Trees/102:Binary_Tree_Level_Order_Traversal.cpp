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
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> tmp;
        if(!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            while(size--) {
                TreeNode *c = q.front();
                q.pop();
                if(c) {
                    tmp.push_back(c->val);
                    if (c->left) {
                        q.push(c->left);
                    }
                    if (c->right) {
                        q.push(c->right);
                    }
                }
            }
            v.push_back(tmp);
            tmp.clear();         
        }
        return v;
    }
};
