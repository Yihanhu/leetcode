// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//
// The order of output does not matter.
//
// Example 1:
//
// Input:
// s: "cbaebabacd" p: "abc"
//
// Output:
// [0, 6]
//
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
//
//
//
// Example 2:
//
// Input:
// s: "abab" p: "ab"
//
// Output:
// [0, 1, 2]
//
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
//
//


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int cs[26] = {0};
        int cp[26] = {0};
        if(s.size()<p.size())
            return res;
        for(int i = 0; i < p.size();i++){
            cp[p[i]-'a']++;
            cs[s[i]-'a']++;
        }
        int diff = 0;
        for(int i = 0; i<26;i++){
            if(cs[i] != cp[i])
                diff++;
        }
        
        if(diff == 0){
            res.push_back(0);
        }
        for(int i = p.size(); i<s.size();i++){
            int c1 = s[i]-'a';
            bool tmp = (cs[c1] == cp[c1]);
            cs[c1]++;
            if(cs[c1] == cp[c1]){
                diff--;
            }
            else{
                if(tmp)
                    diff++;
            }
            int c2 = s[i-p.size()] - 'a';
            tmp = (cs[c2] == cp[c2]);
            cs[c2]--;
            if(cs[c2] == cp[c2]){
                diff--;
            }
            else{
                if(tmp)
                    diff++;
            }
            if(diff == 0){res.push_back(i-p.size()+1);}
        }
        return res;
    }
};
