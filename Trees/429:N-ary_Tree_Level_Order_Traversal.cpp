/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(!root)
            return v;
        vector<int> tmp;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root,0));
        int c = 0;
        while(!q.empty()) {
            Node* curr = q.front().first;
            int k = q.front().second;
            q.pop();
            if (c == k){
                tmp.push_back(curr->val);
            } else {
                v.push_back(tmp);
                tmp.clear();
                tmp.push_back(curr->val);
                c++;
            }
            if((curr->children).size()) {
                for(auto i: curr->children) {
                    q.push(make_pair(i, k+1));
                }
            }
        }
        v.push_back(tmp);
        return v;
    }
};
