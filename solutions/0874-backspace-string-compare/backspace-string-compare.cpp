// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
//
//
// Example 1:
//
//
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
//
//
//
// Example 2:
//
//
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
//
//
//
// Example 3:
//
//
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
//
//
//
// Example 4:
//
//
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
//
//
// Note:
//
//
// 	1 <= S.length <= 200
// 	1 <= T.length <= 200
// 	S and T only contain lowercase letters and '#' characters.
//
//
// Follow up:
//
//
// 	Can you solve it in O(N) time and O(1) space?
//
//
//
//
//
//


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size(), j = T.size();
        while(true){
            int back = 0;
            while(i >=0 and (back or S[i] == '#')){
                back += S[i] == '#'?-1:1;
                i--;
            }
            back = 0;
            while(j>=0 and (back or T[j] == '#')){
                back += T[j] == '#'?1:-1;
                j--;
            }
            if(i < 0 and j < 0)
                return true;
            if(i>=0 and j >=0 and S[i] == T[j]){
                i--;j--;
            }
            else{
                return false;
            }
        }
        return false;
    }
};
