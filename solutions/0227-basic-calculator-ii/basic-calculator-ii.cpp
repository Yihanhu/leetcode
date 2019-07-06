// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: "3+2*2"
// Output: 7
//
//
// Example 2:
//
//
// Input: " 3/2 "
// Output: 1
//
// Example 3:
//
//
// Input: " 3+5 / 2 "
// Output: 5
//
//
// Note:
//
//
// 	You may assume that the given expression is always valid.
// 	Do not use the eval built-in library function.
//
//


class Solution {
public:
    int calculate(string s) {
        vector<int> stack;
        int num = -1;
        char preop = '+';
        for(int i=0; i<s.size(); i++){
            // for(int j = 0; j<stack.size();j++){
            // cout<<stack[j]<<';';
            // }
            // cout<<endl;
            if((s[i] - '0')>=0 and (s[i] - '0') <=9){
                if (num >= 0){
                    num = num*10 + s[i] - '0';
                }
                else{num = s[i] - '0';}
            }
            if ((((s[i] - '0')<0 or (s[i] - '0') >9) and s[i]!=' ') or i == s.size()-1){
                switch(preop){
                    case '+': {stack.push_back(num); break;}
                    case '-': {stack.push_back(-num);break;}
                    case '*': {int tmp = stack.back()*num; stack.pop_back(); stack.push_back(tmp);break;}
                    case '/': {int tmp = stack.back()/num; stack.pop_back(); stack.push_back(tmp);break;}
                }
                num = -1;
                preop = s[i];
            }
            if (s[i] == ' '){
                continue;
            }
        }
        int result =0;
        for(int j = 0; j<stack.size();j++){
            // cout<<stack[j]<<';';
            result += stack[j];
        }
        return result;
    }
};
