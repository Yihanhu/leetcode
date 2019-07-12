// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//
//


class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        vector<bool> isPrime(n-2,true);
        for(int i = 2;i*i<n;i++){
            if(isPrime[i-2]){
                for(int j = i;i*j<n;j++){
                    isPrime[i*j-2] = false;
                }
            }
        }
        int count = 0;
        for(auto t:isPrime){
            // cout<<t;
            if(t)
                count++;
        }
        return count;
    }
};
