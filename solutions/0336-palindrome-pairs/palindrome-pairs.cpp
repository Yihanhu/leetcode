// Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
//
// Example 1:
//
//
//
// Input: ["abcd","dcba","lls","s","sssll"]
// Output: [[0,1],[1,0],[3,2],[2,4]] 
// Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
//
//
//
// Example 2:
//
//
// Input: ["bat","tab","cat"]
// Output: [[0,1],[1,0]] 
// Explanation: The palindromes are ["battab","tabbat"]
//
//
//
//


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> dict;
        vector<vector<int>> res;
        //build map
        for(int i = 0; i<words.size(); i++){
            string word = words[i];
            reverse(word.begin(),word.end());
            dict[word] = i;
        }
        if (dict.find("") != dict.end()){
            for(int i = 0; i<words.size(); i++){
                if(isPalindrome(words[i]) and i!=dict[""]){
                    res.push_back({ i,dict[""] });
                }
            }
        }
        for(int i = 0; i<words.size(); i++){
            for(int j = 0; j< words[i].size();j++){
                string left = words[i].substr(0,j+1);
                string right = words[i].substr(j+1,words[i].size()-(j+1));
                if (dict.find(left)!=dict.end() and isPalindrome(right) and dict[left] != i){
                    res.push_back({ i,dict[left] });
                }
                if (dict.find(right)!=dict.end() and isPalindrome(left)and dict[right] != i){
                    res.push_back( {dict[right],i });
                }
            }
        }
        return res;
    }
    bool isPalindrome(string str){
        for(int i = 0; i<str.size()/2;i++){
            if(str[i] != str[str.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};
