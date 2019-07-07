// Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
//
//  
//
//
// Example 1:
//
//
// Input: [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
//
//
//
// Example 2:
//
//
// Input: [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 10000
// 	-10000 <= A[i] <= 10000
// 	A is sorted in non-decreasing order.
//
//
//


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int i = 0;
        int j = n-1;
        vector<int> res(n,0);
        for(int k = n-1; k >=0 ; k--){
            if(A[i]*A[i] > A[j]*A[j]){
                res[k] = A[i]*A[i];
                i++;
            }
            else{
                res[k] = A[j]*A[j];
                j--;
            }
        }
        return res;
    }
};
