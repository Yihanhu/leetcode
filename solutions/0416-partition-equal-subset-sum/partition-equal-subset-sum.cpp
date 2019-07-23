// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
// Note:
//
//
// 	Each of the array element will not exceed 100.
// 	The array size will not exceed 200.
//
//
//  
//
// Example 1:
//
//
// Input: [1, 5, 11, 5]
//
// Output: true
//
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
//  
//
// Example 2:
//
//
// Input: [1, 2, 3, 5]
//
// Output: false
//
// Explanation: The array cannot be partitioned into equal sum subsets.
//
//
//  
//


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int num_sum = 0;
        for(int i =0; i<nums.size();i++){
            num_sum += nums[i];
        }
        if (num_sum % 2 !=0)
            return false;
        int half = num_sum/2;
        vector<bool> dp(half+1,false);
        dp[0] = true;
        for(int i = 0; i<nums.size();i++){
            for(int j = half; j>=nums[i]; j--){
                dp[j] = dp[j] or dp[j-nums[i]];
                // cout<<dp[j];
            }
            // cout<<endl;
        }      
        return dp[half];
    }
};
