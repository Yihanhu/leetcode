//
// Given a non-empty string s, you may delete at most one character.  Judge whether you can make it a palindrome.
//
//
// Example 1:
//
// Input: "aba"
// Output: True
//
//
//
// Example 2:
//
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
//
//
//
// Note:
//
// The string will only contain lowercase characters a-z.
// The maximum length of the string is 50000.
//
//


class Solution {
public:
    int left = true;
    bool validPalindrome(string s) {
        // cout<<s<<endl;
        int i = 0, j = s.size() - 1;
        while(j > i){
            // cout<<s[i]<<" "<<s[j]<<endl;
            if(s[i] == s[j]){i++;j--;}
            else{
                if(left){
                    left = false;
                    return validPalindrome(s.substr(i+1, j-i)) or validPalindrome(s.substr(i, j-i));
                }
                else{return false;}
            }
        }
        return true;
    }
};
