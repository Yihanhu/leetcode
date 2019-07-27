//
// Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
//
//
// Example 1:
//
// Input: [1,3,5,4,7]
// Output: 3
// Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
// Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
//
//
//
// Example 2:
//
// Input: [2,2,2,2,2]
// Output: 1
// Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
//
//
//
// Note:
// Length of the array will not exceed 10,000.
//


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        int tmp_len = 1;
        int max_len = 0;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i]>nums[i-1]){
                tmp_len ++;
            }
            else{
                if(max_len<tmp_len){
                    max_len = tmp_len;
                }
                tmp_len = 1;
            }
        }
        if(max_len<tmp_len){
            max_len = tmp_len;
        }
        return max_len;
    }
};
