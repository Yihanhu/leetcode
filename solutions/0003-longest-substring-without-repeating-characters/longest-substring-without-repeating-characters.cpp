// Given a string, find the length of the longest substring without repeating characters.
//
//
// Example 1:
//
//
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
//
//
// Example 2:
//
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
//
// Example 3:
//
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
//
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max_len = 0;
        unordered_set<char> hash_map;
        for(int i = 0; i < s.size(); i++){
            if(hash_map.find(s[i]) == hash_map.end())
                hash_map.insert(s[i]);
            else{
                hash_map.erase(hash_map.find(s[start]));
                start++;
                i--;
            }
            if(max_len < hash_map.size())
                max_len = hash_map.size();
        }
        return max_len;
    }
};
