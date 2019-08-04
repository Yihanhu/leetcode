// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
//
// Input: ["flower","flow","flight"]
// Output: "fl"
//
//
// Example 2:
//
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
// Note:
//
// All given inputs are in lowercase letters a-z.
//


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int i = 0;strs.size()>0 ;i++ ){
            for(int j = 0; j<strs.size(); j++){
                if(i >= strs[j].size() or (j>0 and strs[j-1][i]!= strs[j][i])){
                    return strs[j].substr(0,i);
                }
            }
        }
        return prefix;
    }
};
