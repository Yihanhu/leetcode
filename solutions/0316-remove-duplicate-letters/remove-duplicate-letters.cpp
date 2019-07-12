// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
//
// Example 1:
//
//
// Input: "bcabc"
// Output: "abc"
//
//
// Example 2:
//
//
// Input: "cbacdcbc"
// Output: "acdb"
//


class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[256] = {0};
        int visited[256] = {0};
        for(int i = 0; i < s.size(); i++){
            cnt[s[i]]++;
        }
        string res = "0";
        for(auto a:s){
            cnt[a]--;
            if(visited[a]) continue;
            while(a < res.back() and cnt[res.back()]){
                visited[res.back()] = 0;
                res.pop_back();
            }
            res.push_back(a);
            visited[a] = 1;
        }
        return res.substr(1);
    }
};
