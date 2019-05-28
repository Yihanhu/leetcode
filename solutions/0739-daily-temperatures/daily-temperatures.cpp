//
// Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.  If there is no future day for which this is possible, put 0 instead.
//
// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
//
//
// Note:
// The length of temperatures will be in the range [1, 30000].
// Each temperature will be an integer in the range [30, 100].
//


// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         int n = T.size();
//         vector<int> res(n,INT_MAX);
//         vector<int> hash(71,-1);
//         int i = 0;
//         while(!T.empty()){
//             int tmp = T.back();
//             T.pop_back();
//             for(int t = tmp + 1; t <= 100; t++){
//                 if(hash[t - 30]>=0 and i - hash[t-30] > 0){
//                     res[n - i -1] = min(i - hash[t-30], res[n - i -1]);
//                 }
//             }
//             if(res[n - i -1] == INT_MAX)
//                 res[n - i - 1] = 0;
//             hash[tmp-30] = i;
//             i++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n,0);
        for(int i = n - 2; i >=0; i--){
            int j = i+1;
            while(j < n and T[j] <= T[i]){
                if(res[j] > 0) j = j + res[j];
                else
                    j = n;
            }
            if(j <n)
                res[i] = j - i;
        }
        return res;
    }
};
