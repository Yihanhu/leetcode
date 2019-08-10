// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
//
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: [3]
//
// Example 2:
//
//
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
//


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int major1 = -1, major2 = -1, c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == major1)
                c1++;
            else if(nums[i] == major2)
                c2++;
            else if(c1 == 0){
                major1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0){
                major2 = nums[i];
                c2 = 1;
            }
            else{
                c1--;c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        vector<int> res;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] == major1)
                c1++;
            else if(nums[i] == major2)
                c2++;
        }
        if(c1 > int(nums.size()/3))
            res.push_back(major1);
        if(c2 > int(nums.size()/3))
            res.push_back(major2);
        return res;
    }
};
