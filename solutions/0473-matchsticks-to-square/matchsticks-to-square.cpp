// Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//
//  Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
//
// Example 1:
//
// Input: [1,1,2,2,2]
// Output: true
//
// Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
//
//
//
// Example 2:
//
// Input: [3,3,3,3,4]
// Output: false
//
// Explanation: You cannot find a way to form a square with all the matchsticks.
//
//
//
// Note:
//
// The length sum of the given matchsticks is in the range of 0 to 10^9.
// The length of the given matchstick array will not exceed 15.
//
//


//backtracking with pruning
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int total_length = 0;
        for(int i = 0; i < nums.size(); i ++){
            total_length += nums[i];
        }
        if (total_length % 4 != 0|nums.size()<4){
            return false;
        }
        sort(nums.rbegin(), nums.rend());
        int bucket[4] = {0,0,0,0};
        return generate(0, nums, bucket, total_length/4);
    }

private:
    bool generate(int i, vector<int> &nums, int bucket [], int target){
        if(i == nums.size() && bucket[0] == target && bucket[1] == target && bucket[2] == target && bucket[3] == target){
            return true;
        }
        for (int j = 0; j < 4; j++){
            if (bucket[j] + nums[i] > target){
                continue;
            }
            bucket[j] = bucket[j] + nums[i];
            if (generate(i + 1, nums, bucket, target)){
                return true;
            }
            bucket[j] -= nums[i];
        }
        return false;
    }
};

//bit operation
// class Solution {
// public:
//     bool makesquare(vector<int>& nums) {
//         int total_length = 0;
//         for(int i = 0; i < nums.size(); i ++){
//             total_length += nums[i];
//         }
//         if (total_length % 4 != 0|nums.size()<4){
//             return false;
//         }
//         vector<int> sumList;
//         targetsum(0, nums, sumList, total_length/4, 0);
//         vector<int> sumList2;
//         // for(int i = 0; i < sumList.size(); i++){
//         //     cout << bitset<sizeof(int)*8>(sumList[i]) << endl;
//         // }
//         for(int i = 0; i < sumList.size(); i++){
//             for(int j = i+1; j < sumList.size(); j++){
//                 if((sumList[i]&sumList[j]) == 0){
//                     sumList2.push_back(sumList[i]|sumList[j]);
//                 }
//             }
//         }
//         // for(int i = 0; i < sumList2.size(); i++){
//         //     cout << bitset<sizeof(int)*8>(sumList2[i]) << endl;
//         // }
//         for(int i = 0; i < sumList2.size(); i++){
//             for(int j = i+1; j < sumList2.size(); j++){
//                 if((sumList2[i]&sumList2[j]) == 0){
//                     return true;
//                 }
//             }
//         }
//         return false;
        
//         // for(int i = 0; i < sumList.size(); i++){
//         //     cout << bitset<sizeof(int)*8>(sumList[i]) << endl;
//         // }
//         // return true;
//     }
// private:
//     void targetsum(int i,vector<int> &nums, vector<int> &sumList, int sumTarget, int bucket){
//         if(nums[i] == sumTarget){
//             sumList.push_back(bucket | 1<<(nums.size()-i-1));
//             targetsum(i + 1, nums, sumList, sumTarget, bucket);
//         }
//         if(nums[i]< sumTarget && i < nums.size()){
//             targetsum(i + 1, nums, sumList, sumTarget, bucket);
//             targetsum(i + 1, nums, sumList, sumTarget - nums[i], bucket|1<<(nums.size()-i-1));
//         }
//         if(nums[i]> sumTarget && i < nums.size()){
//             targetsum(i + 1, nums, sumList, sumTarget, bucket);
//         }
//     }
// };
