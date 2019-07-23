// Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
//
//
// Note:
// If n is the length of array, assume the following constraints are satisfied:
//
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
//
//
//
// Examples: 
//
// Input:
// nums = [7,2,5,10,8]
// m = 2
//
// Output:
// 18
//
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.
//
//


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long num_sum = 0;
        long long num_max = 0;
        for(int i =0; i<nums.size();i++){
            num_sum += nums[i];
            if (nums[i]>num_max){num_max = nums[i];}
        }
        return generate(nums,num_max,num_sum,m);
    }
    
    int generate(vector<int>& nums, long long left, long long right,int m){
        // cout<<left<<" "<<right<<endl;
        if(left == right){return left;}
        int mid = (left+right)/2;
        // cout<<can_split(nums,mid,m)<<endl;
        if(can_split(nums,mid,m)){
            return generate(nums,left,mid,m);
        }
        else{
            return generate(nums,mid+1,right,m);
        }
    }
    
    bool can_split(vector<int>& nums, long long MAX, int m){
        int num_sum = 0;
        for(int i =0; i< nums.size(); i++){
            num_sum += nums[i];
            if(num_sum>MAX){
                m--;
                if(m<=0){return false;}
                num_sum = nums[i];
            }
        }
        return true;
    }
};
