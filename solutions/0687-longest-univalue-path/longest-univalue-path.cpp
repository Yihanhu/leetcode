// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
// The length of path between two nodes is represented by the number of edges between them.
//
//  
//
// Example 1:
//
// Input:
//
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
//
//
// Output: 2
//
//  
//
// Example 2:
//
// Input:
//
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
//
//
// Output: 2
//
//  
//
// Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        int tup = 0;
        if(root) dfs(root, tup);
        return tup;
    }
    int dfs(TreeNode* root, int& tup){
        int l = 0, r = 0;
        if(root->left){
            l = dfs(root->left, tup);
        }
        if(root->right){
            r = dfs(root->right, tup);
        }
        if(root->left and root->left->val == root->val)
            l++;
        else
            l = 0;
        if(root->right and root->right->val == root->val)
            r++;
        else
            r = 0;
        tup = max(tup,l+r);
        return max(l,r);
    }
};
