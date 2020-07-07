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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> v;
        if(!root)
            return v;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,0));
        int c=0;
        int val = root->val;
        while(!q.empty()) {
            TreeNode* curr  = q.front().first;
            int k = q.front().second;
            q.pop();
            if(c==k) {
                if(curr->val >= val) {
                    val = curr->val;
                }
            } else {
                v.push_back(val);
                val = curr->val;
                c++;
            }
            if(curr->left) {
                q.push(make_pair(curr->left, k+1));
            }
            if(curr->right) {
                q.push(make_pair(curr->right, k+1));
            }
        }
        v.push_back(val);
        return v;
    }
};
