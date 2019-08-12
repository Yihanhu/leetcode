//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int l = n;
        int r = 0;
        vector<string> res;
        string s = "";
        generate(res,l,r,s);
        return res;
    }
    
    void generate(vector<string>& res, int l , int r, string s){
        if(l==0 and r == 0)
            res.push_back(s);
        if(l>0)
            generate(res,l-1,r+1,s+"(");
        if(r>0)
            generate(res,l,r-1,s+")");
    }
};
