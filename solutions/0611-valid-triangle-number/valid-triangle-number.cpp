// Given an array consists of non-negative integers,  your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
//
// Example 1:
//
// Input: [2,2,3,4]
// Output: 3
// Explanation:
// Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
//
//
//
// Note:
//
// The length of the given array won't exceed 1000.
// The integers in the given array are in the range of [0, 1000].
//
//
//


// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int ret = 0;
//         for(int i = 0; i<nums.size(); i++){
//             for(int j = i+1; j<nums.size(); j++){
//                 int pos = bi_sect(nums,j+1, nums.size()-1, nums[i]+nums[j]);
//                 while(nums[pos] >= nums[i]+nums[j])
//                     pos--;
//                 // cout<<i<<" "<<j<<" "<<pos<<endl;
//                 if(pos - j>0){
//                     ret += pos - j;
//                 }
//             }
//         }
//         return ret;
//     }
    
//     int bi_sect(vector<int>& nums,int start, int ends, int target){
//         if(start - ends <= 0)
//             ends++;
//             ends--;
//             return ends;
//         int mid = (ends - start)/2 + start;
//         if(target > nums[mid]){
//             return bi_sect(nums,mid+1, ends, target);
//         }
//         else{
//             return bi_sect(nums, start ,mid - 1, target);
//         }
        
//     }
// };

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = 2; i < nums.size(); i++){
            int l = 0;
            int r = i-1;
            while(l<r){
                if(nums[r]+nums[l]>nums[i]){
                    count += r - l;
                    r--;
                }
                else
                    l++;
            }
        }
        return count;
    }
};
