// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
//
//
// The flattened tree should look like:
//
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
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
    void flatten(TreeNode* root) {
        TreeNode* last = NULL;
        preorder(root, last);
        
    }
    
private:
    void preorder(TreeNode * node, TreeNode * &last){
        if(!node){
            return;
        }
        if(!node->left && !node->right){
            last = node;
            return;
        }
        TreeNode * left = node->left;
        TreeNode * right = node->right;
        TreeNode * left_last = NULL;
        TreeNode * right_last = NULL;
        if (left){
            preorder(left, left_last);
            // node->right = left;
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if(right){
            preorder(right, right_last);
            if (left_last){
                left_last->right = right;
            }
            last = right_last;
        }
        
    }
};
