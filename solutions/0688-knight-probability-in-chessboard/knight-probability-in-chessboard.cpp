// On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
//
// A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
//
//  
//
//
//
//  
//
// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
//
// The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.
//
//  
//
// Example:
//
//
// Input: 3, 2, 0, 0
// Output: 0.0625
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.
//
//
//  
//
// Note:
//
//
// 	N will be between 1 and 25.
// 	K will be between 0 and 100.
// 	The knight always initially starts on the board.
//
//


class Solution {
public:
    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N,vector<double>(N,1));
        for(int i = 0; i < K ; i++){
            vector<vector<double>> dp_copy(N,vector<double>(N,0));
            for(int x = 0; x < N; x++){
                for(int y = 0; y < N; y++){
                    for(int j = 0; j < 8; j++){
                        int new_x = x + dx[j];
                        int new_y = y + dy[j];
                        if(new_x >=0 and new_x < N and new_y >=0 and new_y < N){
                            // cout<<x<<" "<<y<<" "<<new_x<<" "<<new_y<<endl;
                            dp_copy[x][y] += 0.125 * dp[new_x][new_y]; 
                            // cout<<dp_copy[x][y]<<endl;
                        }
                    }
                }
            }
            for(int x = 0; x < N; x++){
                for(int y = 0; y < N; y++){
                    dp[x][y] = dp_copy[x][y];
                }
            }
        }
        return dp[r][c];
    }
};
