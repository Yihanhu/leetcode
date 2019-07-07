// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
//
// Return the intersection of these two interval lists.
//
// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
//
//
//  
//
// Example 1:
//
//
//
//
// Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
// Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
//
//
//  
//
// Note:
//
//
// 	0 <= A.length < 1000
// 	0 <= B.length < 1000
// 	0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
//
//
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
//
//


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int As = 0, Ae = 0,Bs = 0,Be = 0;
        int a = 0;
        int b = 0;
        vector<vector<int>> res;
        while(a<A.size() and b < B.size()){
            // cout<<a<<b<<endl;
            if(As < A[a][0])
                As = A[a][0];
            Ae = A[a][1];
            if(Bs < B[b][0]) 
                Bs = B[b][0];
            Be = B[b][1];
            int s = max(As, Bs);
            int e = min(Ae,Be);
            // cout<<s<<" "<<e<<endl;
            if(e < s and Ae < Bs){
                a++;
                continue;
            }
            else if(e < s and Ae >= Bs){
                b++;
                continue;
            }
            // cout<<s<<" "<<e<<endl;
            res.push_back(vector<int>{s,e});
            if(e == Ae){
                a++;
                Bs = e;
            }
            else{
                b++;
                As = e;
            }
        }
        return res;
        
    }
};
