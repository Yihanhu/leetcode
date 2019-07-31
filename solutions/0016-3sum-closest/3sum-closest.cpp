// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = INT_MAX;
        int dis_sum = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            int two_target = target-nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                int sum = nums[start] + nums[end];
                if(dis_sum > abs(two_target-sum)){
                    dis_sum = abs(two_target - sum);
                    closest_sum = sum + nums[i];
                }
                if(sum<two_target)
                    start++;
                else if(sum>two_target)
                    end --;
                else
                    return sum+nums[i];
            }
        }
        return closest_sum;
    }
};
