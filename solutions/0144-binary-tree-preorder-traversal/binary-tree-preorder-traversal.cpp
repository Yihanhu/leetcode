// Given a binary tree, return the preorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,2,3]
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*,int>> st;
        if(root)
            st.push(make_pair(root, 0));
        while(!st.empty()){
            TreeNode* ptr = st.top().first;
            int mark = st.top().second;
            st.top().second = 1;
            if(!mark)
                res.push_back(ptr->val);
            while(ptr->left and !mark){
                res.push_back(ptr->left->val);
                st.push(make_pair(ptr->left, 1));
                ptr = ptr->left;
            }
            st.pop();
            if(ptr->right){
                st.push(make_pair(ptr->right,0));
            }
        }
        return res;
    }
};
