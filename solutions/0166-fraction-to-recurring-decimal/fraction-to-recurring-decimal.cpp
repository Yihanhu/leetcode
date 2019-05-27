// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
// If the fractional part is repeating, enclose the repeating part in parentheses.
//
// Example 1:
//
//
// Input: numerator = 1, denominator = 2
// Output: "0.5"
//
//
// Example 2:
//
//
// Input: numerator = 2, denominator = 1
// Output: "2"
//
// Example 3:
//
//
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
//
//


class Solution {
public:
    string fractionToDecimal(int numeratori, int denominatori) {
        string ret = "";
        if((numeratori < 0 and  denominatori >0) or (numeratori > 0 and denominatori <0))
            ret += '-';
        long numerator =  abs(static_cast<long> (numeratori));
        long denominator = abs(static_cast<long> (denominatori));
        long digit = numerator / denominator;
        string tmp = "";
        while(digit > 0){
            tmp = static_cast<char>('0' + digit %10) + tmp;
            digit = digit/10;
        }
        ret += tmp;
        long res = numerator % denominator;
        if(ret == "" or ret == "-")
            ret += '0';
        if(res)
            ret += '.';
        unordered_map<long,int> map;
        int pos = 0;
        tmp = "";
        while(res){
            long digit = res*10 / denominator;
            // cout<<res<<endl;
            if(map.find(res) != map.end()){
                tmp.insert(map[res], "(");
                return ret + tmp + ')';
            }
            map[res] = pos++;
            res = (res*10) % denominator;
            tmp += static_cast<char>('0' + digit);
            // cout<<tmp<<endl;
        }
        return ret + tmp;
    }
};
