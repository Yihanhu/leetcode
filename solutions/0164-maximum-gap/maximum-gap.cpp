// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
// Return 0 if the array contains less than 2 elements.
//
// Example 1:
//
//
// Input: [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either
//              (3,6) or (6,9) has the maximum difference 3.
//
// Example 2:
//
//
// Input: [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//
// Note:
//
//
// 	You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// 	Try to solve it in linear time/space.
//
//


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxV = INT_MIN;
        int minV = INT_MAX;
        if(nums.size() < 2)
            return 0;
        for(int i = 0; i < nums.size();i++){
            maxV = max(maxV, nums[i]);
            minV = min(minV, nums[i]);
        }
        int min_gap = (maxV - minV)/nums.size() + 1;
        int num_buck = (maxV - minV) / min_gap +1;
        cout<<min_gap<<num_buck<<endl;
        vector<int> buck_max(num_buck, INT_MIN);
        vector<int> buck_min(num_buck, INT_MAX);
        vector<int> buck_num(num_buck, 0);
        for(int i =0; i < nums.size();i++){
            int num = (nums[i] - minV)/min_gap;
            buck_num[num]++;
            buck_min[num] = min(buck_min[num], nums[i]);
            buck_max[num] = max(buck_max[num], nums[i]);
        }
        int max_gap = INT_MIN;
        int last_max = minV;
        for(int i = 0; i < num_buck; i++){
            if(buck_num[i] > 0){
                max_gap = max(max_gap, buck_min[i] - last_max);
                last_max = buck_max[i];
            }
        }
        return max_gap;
    }
};
