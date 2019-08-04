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
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < static_cast<int>(nums.size()) -2; i++){
            int target = -nums[i];
            if(target < 0)
                break;
            if(i >= 1 and nums[i] == nums[i-1])
                continue;
            int s = i + 1;
            int e = nums.size() - 1;
            while(s < e){
                if(nums[s] + nums[e] == target){
                    // cout<<s<<e<<endl;
                    res.push_back({nums[i], nums[s], nums[e]});
                    s++;e--;
                    while(s < e and nums[s] == nums[s-1]){s++;}
                    while(e > s and nums[e] == nums[e+1]){e--;}
                    continue;
                }
                else if(nums[s] + nums[e] > target) {e--;}
                else{s++;}
            }
        }
        return res;
    }
};
