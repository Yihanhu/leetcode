// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
// Example:
//
//
// X X X X
// X O O X
// X X O X
// X O X X
//
//
// After running your function, the board should be:
//
//
// X X X X
// X X X X
// X X X X
// X O X X
//
//
// Explanation:
//
// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
//


class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    int m = 0, n = 0;
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0)
            return;
        n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        // vector<vector<int>> unchanged(m, vector<int>(n,0));
        for(int i = 0; i < m;i++){
            if(!visited[i][0] and board[i][0] == 'O')
                dfs(board, i, 0, visited);
            if(!visited[i][n-1] and board[i][n-1] == 'O')
                dfs(board, i , n-1, visited);
        }
        for(int j = 1; j< n-1;j++){
            if(!visited[0][j] and board[0][j] == 'O'){
                dfs(board, 0, j, visited);
            }
            if(!visited[m-1][j] and board[m-1][j] == 'O'){
                dfs(board, m-1, j, visited);
            }
        }
        for(int i = 0 ; i < m ; i ++){
            for(int j =0; j < n; j++){
                if(board[i][j] == 'O' and !visited[i][j])
                    board[i][j] = 'X';
            }
        }
        
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>>& visited){
        visited[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int new_x = dx[k] + i;
            int new_y = dy[k] + j;
            if(new_x >=0 and new_x < m and new_y >=0 and new_y <n and board[new_x][new_y] == 'O' and !visited[new_x][new_y]){
                dfs(board,new_x,new_y,visited);
            }
        }
    }
};
