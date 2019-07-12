// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
//
//  
//
// Example:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
//
// Output:  [1,2,4,7,5,3,6,8,9]
//
// Explanation:
//
//
//
//  
//
// Note:
//
// The total number of elements of the given matrix will not exceed 10,000.
//


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m)
            return {};
        int n = matrix[0].size();
        vector<int> res(m*n,0);
        int dir = 1, i = 0, j = 0;
        for(int k = 0; k < m*n;k ++){
            cout<<i<<j<<endl;
            res[k] = matrix[i][j];
            i-= dir;
            j+= dir;
            if(dir == 1 and i <0 and j >= n){
                i += dir;
                j -= dir;
                dir = -dir;
                i++;
                continue;
            }
            if(dir == -1 and i >=m and j < 0){
                i += dir;
                j -= dir;
                dir = -dir;
                j++;
                continue;
            }
            if(i >=m  or i <0 ){
                i += dir;
                j -= dir;
                dir = -dir;
                j++;
            }
            if(j >=n or j <0){
                i += dir;
                j -= dir;
                dir = -dir;
                i++;
            }
        }
        return res;
    }
};
