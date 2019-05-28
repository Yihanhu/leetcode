// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n  = matrix[0].size();
        if(n == 0)
            return false;
        int lo = 0;
        int hi = m-1;
        while(lo < hi){
            // cout<<lo<< hi<<endl;
            // cout<<matrix[lo]<<" "<<matrix[first][hi]<<endl;
            if(hi - lo == 1)
                break;
            int mid = (lo + hi)/2;
            if(matrix[mid][0] < target)
                lo = mid;
            else if(matrix[mid][0] > target)
                hi = mid;
            else
                return true;
        }
        if(matrix[lo][0] == target or matrix[hi][0] == target)
            return true;
        int first = lo;
        if(matrix[hi][0] < target)
            first = hi;
        lo = 0, hi = n-1;
        while(lo < hi){
            if(hi - lo == 1)
                break;
            int mid = (lo + hi)/2;
            if(matrix[first][mid] < target)
                lo = mid;
            else if(matrix[first][mid] > target)
                hi = mid;
            else
                return true;
        }
        return matrix[first][lo] == target or matrix[first][hi] == target;
    }
};
