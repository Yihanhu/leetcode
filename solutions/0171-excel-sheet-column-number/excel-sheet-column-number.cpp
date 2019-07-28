// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//
//
//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
//     ...
//
//
// Example 1:
//
//
// Input: "A"
// Output: 1
//
//
// Example 2:
//
//
// Input: "AB"
// Output: 28
//
//
// Example 3:
//
//
// Input: "ZY"
// Output: 701
//


class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int power = 0;
        for(int i =s.size()-1; i >=0; i--){
            res += (static_cast<int>(s[i] - 'A') + 1)*pow(26,power++);
        }
        return res;
    }
};
