// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
//
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return NULL;
        return helper(nums, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& nums, int i, int j){
        int mid = (i+j)/2;
        // cout<<i <<" "<<j<<" "<<mid<<endl;
        TreeNode* lnode = NULL; 
        TreeNode* rnode = NULL; 
        TreeNode* root = NULL; 
        if(i <= mid - 1)
            lnode = helper(nums, i, mid -1);
        if(j >= mid + 1)
            rnode = helper(nums, mid + 1, j);
        root = new TreeNode(nums[mid]);
        root->left = lnode;
        root->right = rnode;
        return root;
    }   
};
