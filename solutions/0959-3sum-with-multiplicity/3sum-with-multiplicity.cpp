// Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.
//
// As the answer can be very large, return it modulo 10^9 + 7.
//
//  
//
// Example 1:
//
//
// Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation: 
// Enumerating by the values (A[i], A[j], A[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.
//
//
//
// Example 2:
//
//
// Input: A = [1,1,2,2,2,2], target = 5
// Output: 12
// Explanation: 
// A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
// We choose one 1 from [1,1] in 2 ways,
// and two 2s from [2,2,2,2] in 6 ways.
//
//
//  
//
//
// Note:
//
//
// 	3 <= A.length <= 3000
// 	0 <= A[i] <= 100
// 	0 <= target <= 300
//


class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        sort(A.begin(),A.end());
        long count = 0;
        long M = 1e9 + 7;
        // cout<<M<<endl;
        for(int i = 0; i < A.size(); i++){
            // cout<<count<<" ";
            int start = i+1;
            int end = A.size()-1;
            int two_target = target - A[i];
            while(start<end){
                long count_a = 0;
                long count_b = 0;
                int sum = A[start] + A[end];
                if(sum > two_target)
                    end --;
                else if(sum<two_target)
                    start++;
                else{
                    int a = A[start];
                    int b = A[end];
                    if(a!=b){
                        while(start<end and A[start] == a){start++; count_a++;}
                        while(start<=end and A[end] == b){end--; count_b++;}
                        count += count_a*count_b;
                    }
                    else{
                        while(start<=end and A[end] == b){end--; count_b++;}
                        count += count_b*(count_b - 1)/2;
                    }
                }
            }
        }
        return count%M;
    }
};
