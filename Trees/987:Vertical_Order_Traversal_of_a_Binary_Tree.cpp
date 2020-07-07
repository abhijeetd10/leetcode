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
typedef struct Point {
    int x;
    int y;
}Point;
bool mysorty(const pair<TreeNode*,Point> &a, const pair<TreeNode*,Point> &b) 
{ 
    return (a.second.y > b.second.y); 
}

bool mysortx(const pair<TreeNode*,Point> &a, const pair<TreeNode*,Point> &b) 
{ 
    return (a.second.x < b.second.x); 
}

bool mysortval(const pair<TreeNode*,Point> &a, const pair<TreeNode*,Point> &b) 
{ 
    return ((a.first)->val < (b.first)->val); 
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> new_v;
        if(!root)
            return v;
        queue<pair<TreeNode*, Point>> q;
        vector<pair<TreeNode*, Point>> tmp;
        Point co = {0,0};
        q.push(make_pair(root, co));
        tmp.push_back(make_pair(root, co));
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            Point curr_cd = q.front().second;
            q.pop();
            if(curr->left) {
                Point l = {curr_cd.x - 1, curr_cd.y - 1};
                q.push(make_pair(curr->left, l));
                tmp.push_back(make_pair(curr->left, l));
            }
            if(curr->right) {
                Point r = {curr_cd.x + 1, curr_cd.y - 1};
                q.push(make_pair(curr->right, r));
                tmp.push_back(make_pair(curr->right, r));
            }
        }
        
        sort(tmp.begin(), tmp.end(), mysortval);        
        stable_sort(tmp.begin(), tmp.end(), mysorty);
        stable_sort(tmp.begin(), tmp.end(), mysortx);
        int j = tmp[0].second.x;
        int ch = (tmp[0].first)->val;
        for(int i=1;i<tmp.size();i++){
            if (tmp[i].second.x != j) {
                new_v.push_back(ch);
                ch = (tmp[i].first)->val;
                v.push_back(new_v);
                new_v.clear();
                j = tmp[i].second.x;
            } else {
                new_v.push_back(ch);
                ch = (tmp[i].first)->val;
            }
        }
        new_v.push_back(ch);
        v.push_back(new_v);
        return v;
    }
};
