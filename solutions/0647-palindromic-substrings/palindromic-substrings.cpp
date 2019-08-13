// Given a string, your task is to count how many palindromic substrings in this string.
//
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
// Example 1:
//
//
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
//
//
//  
//
// Example 2:
//
//
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//
//
//  
//
// Note:
//
//
// 	The input string length won't exceed 1000.
//
//
//  
//


class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i<s.size(); i++){
            for(int j = 0; i-j>=0 and i+j<s.size() and s[i-j] == s[i+j]; j++) count++;//check odd len
            for(int j = 1; i-j>=0 and i+j-1<s.size() and s[i-j] == s[i+j-1]; j++) count++;
        }
        return count;
    }
};
