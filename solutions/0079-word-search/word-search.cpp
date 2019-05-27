// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
//


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if(board.size() == 0)
            return false;
        n = board[0].size();
        slen = word.size();
        vector<vector<int>> visited(m,vector<int>(n,0)); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(board, word, 0, i,j,visited))
                    return true;
            }
        }
        return false;
    }
private:
    int m;
    int n;
    int slen;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool dfs(vector<vector<char>>& board, string& word, int wpos, int i, int j, vector<vector<int>>& visited){
        // cout<<i<<" "<<j<<" "<<word[wpos]<<board[i][j]<<endl;
        if(wpos == slen)
            return true;
        if(i<0 or i >=m or j <0 or j >=n or board[i][j] != word[wpos] or visited[i][j])
            return false;
        // cout<<i<<" "<<j<<endl;
        visited[i][j] = 1;
        for(int k = 0; k <4; k++){
            if(dfs(board, word, wpos+1, i+dx[k],j+dy[k],visited))
                return true;
        }
        visited[i][j] = 0;
        return false;
    }
};
