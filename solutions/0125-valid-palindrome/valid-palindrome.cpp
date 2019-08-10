// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0 ,j = s.size() - 1;
        
        while(i<j){
            char a = s[i],b = s[j];
            if(((s[i] < 'A') or (s[i]>'Z' and s[i]<'a') or (s[i]>'z')) and (!isdigit(s[i]))){i++;continue;}
            if(((s[j] < 'A') or (s[j]>'Z' and s[j]<'a') or (s[j]>'z')) and (!isdigit(s[j]))){j--;continue;}
            if(s[i] < 'a' and !isdigit(s[i])){a = s[i] + 32;}
            else{ a = s[i];}
            if(s[j] < 'a' and !isdigit(s[j])){b = s[j] + 32; }
            else{ b = s[j];}
            // cout<<a<<" "<<s[i]<<" "<<b<<" "<<s[j]<<endl;
            if(a == b){i++;j--;}
            else{return false;}
        }
        return true;
    }
};
