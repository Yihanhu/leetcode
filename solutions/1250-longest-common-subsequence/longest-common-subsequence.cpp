// Given two strings text1 and text2, return the length of their longest common subsequence.
//
// A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.
//
//  
//
// If there is no common subsequence, return 0.
//
//  
// Example 1:
//
//
// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
//
//
// Example 2:
//
//
// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
//
//
// Example 3:
//
//
// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
//
//
//  
// Constraints:
//
//
// 	1 <= text1.length <= 1000
// 	1 <= text2.length <= 1000
// 	The input strings consist of lowercase English characters only.
//
//


class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        int m = text1.size();
        int n = text2.size();
        if(m < n)
            return longestCommonSubsequence( text2,text1);
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <=n; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i%2][j] = dp[(i+1)%2][j-1]+1;
                else
                    dp[i%2][j] = max(dp[(i+1)%2][j], dp[(i)%2][j-1]);
            }
        }
        return dp[(m)%2][n];
    }
};
