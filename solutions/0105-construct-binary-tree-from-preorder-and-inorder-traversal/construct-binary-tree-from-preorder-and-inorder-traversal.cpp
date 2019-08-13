// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, (int) inorder.size() - 1);    
        }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int preindex, int instart, int inend ){
        if(instart>inend){return NULL;}
        int inindex = 0;
        TreeNode* root = new TreeNode(preorder[preindex]);
        for(int i = instart; i<=inend;i++){
            if(root->val == inorder[i])
                inindex = i;
        }
        root->left = helper(preorder,inorder,preindex+1,instart,inindex-1);
        root->right = helper(preorder,inorder,preindex+inindex-instart+1,inindex+1,inend) ;
        return root;
    }
};
