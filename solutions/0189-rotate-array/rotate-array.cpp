// Given an array, rotate the array to the right by k steps, where k is non-negative.
//
// Example 1:
//
//
// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
//
//
// Example 2:
//
//
// Input: [-1,-100,3,99] and k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
//
//
// Note:
//
//
// 	Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// 	Could you do it in-place with O(1) extra space?
//


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 0)
            return;
        k = k%n;
        int realstart = 0;
        for(int i = 0; i < n; ){
            int start = realstart;
            int tmp = nums[start];
            do{
                nums[start] = nums[(n + start - k)%n];
                start = (n + start - k)%n; 
                i++;
            }while((n + start - k)%n != realstart);
            nums[start] = tmp;
            i++;
            realstart++;
        }
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size(), start = 0;
//         for (; k %= n; n -= k, start += k) {
//             for (int i = 0; i < k; i++) {
//                 swap(nums[start + i], nums[start + n - k + i]);
//             }
//         }
//     }
// };
