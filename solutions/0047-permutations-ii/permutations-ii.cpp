// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        generate(nums,nums.size()-1, res, tmp);
        return res;
    }
    
    void generate(vector<int> nums, int last, vector<vector<int>>& res,vector<int>&tmp){
        if(last == -1){
            res.push_back(tmp);
        }
        for(int i = last; i >=0; i--){
            if(i != last and nums[i] == nums[last]){continue;} // interesting here, last pos save the choosen 
            tmp.push_back(nums[i]);      //num, one it is the same with the choosen num, it continue, will not 
            swap(nums[i],nums[last]);  //choose the choosen one for same level, once different, it change. 
            generate(nums,last-1,res,tmp); //also, it will not affect the sorted order, since only same num 
            tmp.pop_back();  // are skipped!
        }
    }
};
