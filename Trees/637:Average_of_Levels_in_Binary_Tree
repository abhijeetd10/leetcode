
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root)
            return res;
        double sum=0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,0));
        int c = 0, k = 0, cnt = 0;
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int k = q.front().second;
            q.pop();
            if(c==k){
                sum += curr->val;
                cnt++;
            } else {
                c++;
                res.push_back(sum/cnt);
                sum = 0;
                cnt = 0;
                sum = curr->val;
                cnt++;
            }
            if (curr->left) {
                q.push(make_pair(curr->left, k+1));
            }
            if (curr->right) {
                q.push(make_pair(curr->right, k+1));
            }
        }
        res.push_back(sum/cnt);
        return res;
    }
};
