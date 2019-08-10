// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//


class Solution {
public:
    struct TreeNode{
        int val;
        int count;
        int small_count;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), count(0), small_count(0), left(NULL),right(NULL) {}
    };

    void insert_node(TreeNode* root, TreeNode* node){
        if (node->val > root->val){
            node->small_count += root->count + 1;
            if (root->right){
                insert_node(root->right, node);
            }
            else{
                root->right = node;
            }
        } 
        else{
            root->count ++;
            if (root->left){
                insert_node(root->left, node);
            }
            else{
                root->left = node;
            }
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        vector<TreeNode *> tree;
        int n = nums.size();
        if (n ==0){
            return result;
        }
        TreeNode *root = new TreeNode(nums[n-1]);
        tree.push_back(root);
        for(int i = n - 2; i >= 0; i--){
            TreeNode * p = new TreeNode(nums[i]);
            tree.push_back(p);
            insert_node(root, p);
        }
        for (int i = n-1; i >= 0; i--){
            result.push_back(tree[i]->small_count);
        }
        return result;
    }
}; 
        

