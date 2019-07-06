// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Example 1:
//
//
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
//
//
// Example 2:
//
//
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.
//


class Solution {
public:
    int generate(vector<int>&nums, int left, int right, int k){
        int length = right - left;
        int p = rand() % length + left;
        swap(nums[p],nums[left]);
        p = left;
        int i = left+1;
        int r = right;
        while(p<r-1){
            if (nums[p]<nums[i]){
                swap(nums[p],nums[i]);
                p++;
                i++;
            }
            else{
                swap(nums[i],nums[r-1]);
                r--;
            }
        }
        if(p+1>k){
            return generate(nums,left,p,k);
        }
        else if (p+1<k){
            return generate(nums,p+1,right,k);
        }
        else{
            return nums[p];
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return generate(nums,0,nums.size(),k);
    }
};
