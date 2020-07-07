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

bool isbst(TreeNode* root, pair<long, long> check) {
    cout<<"root->val:"<<root->val<<" "<<"1st:"<<check.first<<" "<<"2nd:"<<check.second<<endl;
    if(!root)
        return true;
    if(root->left) {
        long second = check.second;
        check.second = root->val;
        if(!isbst(root->left, check))
            return false;
        check.second = second;
    }
    if(root->right) {
        long first = check.first;
        check.first = root->val;
        if(!isbst(root->right, check))
            return false;
        check.first = first;
    }
    if(root->val > check.first && root->val < check.second)
        return true;
    else
        return false;   
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        pair<long, long> check;
        check.first = LONG_MIN; 
        check.second = LONG_MAX;
        return (isbst(root, check));
    }
};
