// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
// Example:
//
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    deque<pair<TreeNode*, int>> dq;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        dq.push_back(make_pair(root,0));
        while(!dq.empty()){
            TreeNode* ptr = dq.front().first;
            int level = dq.front().second;
            dq.pop_front();
            if(dq.empty() or dq.front().second > level)
                res.push_back(ptr->val);
            if(ptr->left)
                dq.push_back(make_pair(ptr->left,level+1));
            if(ptr->right)
                dq.push_back(make_pair(ptr->right, level+1));
        }
        return res;
    }
};
