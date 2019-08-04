// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()){
            return -1;
        }
        int begin = 0;
        int end = nums.size()-1;
        int begin_val = nums[begin];
        // int end_val = nums[end];
        while (begin<=end){
            int mid = (begin + end)/2;
            // cout <<nums[begin]<<nums[mid]<<'\n';
            if (target == nums[mid]){
                return mid;
            }
            if (target > nums[mid]){
                if (begin_val <= nums[mid]){
                    begin = mid + 1;
                }
                else{
                    if (target < begin_val){
                        begin = mid +1 ;
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
            if (target < nums[mid]){
                if (begin_val <= nums[mid]){
                    if (target >= begin_val){
                        end = mid - 1;    
                    }
                    else{
                        begin = mid + 1;
                    }
                    
                }
                else{
                    end = mid -1;
                }
            }
            cout << begin<<end<<mid<<'\n';
        }
        return -1;
    }
};
