// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size()+1,INT_MAX);
        dp[1] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            for(int j = triangle[i].size(); j > 0; j--){
                dp[j] = min(dp[j-1],dp[j]) + triangle[i][j-1];
            }
        }
        return *min_element(dp.begin(),dp.end());
    }
};
