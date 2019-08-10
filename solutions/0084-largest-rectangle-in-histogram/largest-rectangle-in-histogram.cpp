// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//  
//
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//  
//
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//  
//
// Example:
//
//
// Input: [2,1,5,6,2,3]
// Output: 10
//
//


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int res = 0;
        for(int i = 0 ; i < heights.size(); i++){
            if(st.empty() or heights[i] > heights[st.top()]){
                st.push(i);
            }
            else{
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
                i--;
            }
        }
        return res;
    }
};
