// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); i++){
            int target = -nums[i]; 
            int start = i+1;
            int end = nums.size() - 1;
            while(start < end){
                int sum = nums[start] + nums[end];
                if(sum < target){
                    start ++;
                }
                else if(sum > target){
                    end --;
                }
                else{
                    int a = nums[start];
                    int b = nums[end];
                    res.push_back({nums[start],nums[end],-target});
                    while(start < end and nums[start] == a) start++;
                    while(start < end and nums[end] == b) end--;
                }
            }
             while(i+1<nums.size() and nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};
