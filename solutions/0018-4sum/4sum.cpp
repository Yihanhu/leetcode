// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); i++){
            int target3 = target-nums[i];
            for(int j = i+1; j<nums.size(); j++){
                int target2 = target3-nums[j];
                // cout<<target2<<endl;
                int start = j+1;
                int end = nums.size() - 1;
                while(start < end){
                    int sum = nums[start] + nums[end];
                    if(sum < target2){
                        start ++;
                    }
                    else if(sum > target2){
                        end --;
                    }
                    else{
                        int a = nums[start];
                        int b = nums[end];
                        res.push_back({nums[start],nums[end],target3-target2,target-target3});
                        while(start < end and nums[start] == a) start++;
                        while(start < end and nums[end] == b) end--;
                    }
                }
                while(j+1<nums.size() and nums[j] == nums[j+1]) j++;
            }
            while(i+1<nums.size() and nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};
