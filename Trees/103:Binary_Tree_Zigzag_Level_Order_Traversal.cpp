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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)
            return v;
        vector<int> tmp;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,0));
        int c = 0;
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int k = q.front().second;
            q.pop();
            if(c==k) {
                if(c%2==0) {
                    tmp.push_back(curr->val);
                } else {
                    tmp.insert(tmp.begin(), curr->val);
                }
            } else {
                v.push_back(tmp);
                tmp.clear();
                tmp.push_back(curr->val);
                c++;
            }
            if(curr->left)
                q.push(make_pair(curr->left, k+1));
            if(curr->right)
                q.push(make_pair(curr->right, k+1));
        }
        v.push_back(tmp);
        return v;
    }
};
