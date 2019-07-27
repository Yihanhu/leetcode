// Given a binary tree, return the postorder traversal of its nodes' values.
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
// Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        vector<int> res;
        if(root)
            st.push(make_pair(root,0));
        while(!st.empty()){
            TreeNode* ptr = st.top().first;
            int mark = st.top().second;
            // cout<<ptr->val<<endl;
            if(mark == 2){
                res.push_back(ptr->val);
                st.pop();
                continue;
            }
            st.top().second = 1;
            while(ptr->left and !mark){
                st.push(make_pair(ptr->left,1));
                ptr = ptr->left;
            }
            st.top().second = 2;
            if(ptr->right){
                st.push(make_pair(ptr->right,0));
            }
        }
        return res;
    }
};
