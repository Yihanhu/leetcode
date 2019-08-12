// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6
//
//


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<int> dp(n, 0);
        int res = 0;
        int cur = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j <n; j++){
                if(matrix[i][j] == '1')
                    dp[j]++;
                else
                    dp[j] = 0;
            }
            res = max(maxRec(dp),res);
        }
        return res;
    }
    
    int maxRec(vector<int>& dp){
        stack<int> st;
        dp.push_back(0);
        int res = 0;
        for(int i = 0; i < dp.size(); i++){
            if(st.empty() or dp[i] > dp[st.top()]){
                st.push(i);
            }
            else{
                int cur = st.top();
                st.pop();
                res = max(res,dp[cur]*(st.empty()? i: (i - st.top() - 1)));
                i--;
            }
        }
        dp.pop_back();
        return res;
    }
};
