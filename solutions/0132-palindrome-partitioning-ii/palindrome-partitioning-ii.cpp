// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//
//


class Solution {
public:   
    int minCut(string s) {
        int n = s.size();
        vector<int> minnum(n+1,0); //minnnum[k] is mincut of first k nums;
        for(int i = 0; i < n+1; i++){minnum[i] = i - 1;}
        for(int i = 0; i < s.size(); i++ ){ //i is the center point
            for(int j = 0; i - j >=0 and i+j<n and s[i-j] == s[i+j];j++) // check odd length
                minnum[i+j+1] = min(minnum[i+j+1],minnum[i-j]+1);
            for(int j = 1; i - j >=0 and i+j<n+1 and s[i-j] == s[i+j-1];j++) // check odd length
                minnum[i+j] = min(minnum[i+j],minnum[i-j]+1);
        }
        return minnum[n];
    }
};
