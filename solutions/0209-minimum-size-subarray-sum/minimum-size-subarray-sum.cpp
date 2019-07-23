// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
// Example: 
//
//
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
//


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sums(nums.size()+1,0);
        for(int i = 0; i < nums.size();i++){
            sums[i+1] = sums[i]+nums[i];
        }
        int i = 0, j = 0;
        int res = INT_MAX;
        while(j <nums.size()+1){
            if(sums[j] - sums[i] < s)
                j++;
            else{
                res = min(res, j-i);
                i++;
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }
};
