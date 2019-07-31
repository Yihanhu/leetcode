// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
// Example 1:
//
//
// Input: "2-1-1"
// Output: [0, 2]
// Explanation: 
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
//
// Example 2:
//
//
// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
// Explanation: 
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
//


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '+' or input[i] == '-' or input[i] =='*'){
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(auto l:left){
                    for(auto r:right){
                        if(input[i] == '+')
                            res.push_back(l + r);
                        else if(input[i] == '-')
                            res.push_back(l - r);
                        else
                            res.push_back(l*r);
                    }
                }
            }
        }
        if(res.size() == 0)
            res.push_back(stoi(input));
        return res;
    }
};
