// Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
//
// Note:
// The array size can be very large. Solution that uses too much extra space will not pass the judge.
//
// Example:
//
//
// int[] nums = new int[] {1,2,3,3,3};
// Solution solution = new Solution(nums);
//
// // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
// solution.pick(3);
//
// // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
// solution.pick(1);
//
//


class Solution {
public:
    vector<int> stream;
    Solution(vector<int> nums) {
        stream = nums;
        // cout<<&stream;
    }
    
    int pick(int target) {
        int index = -1;
        int count = 0;
        for(int i = 0; i <stream.size();i++){
            if(stream[i] == target){
                if(count == 0){index = i;count++;}
                else{
                    count++;
                    if(rand() % count == 0){
                        index = i;
                    }
                }
            }
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
