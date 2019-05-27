// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
//  
//
// Example:
//
//
// Input: 
// board = [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// words = ["oath","pea","eat","rain"]
//
// Output: ["eat","oath"]
//
//
//  
//
// Note:
//
//
// 	All inputs are consist of lowercase letters a-z.
// 	The values of words are distinct.
//
//


class TrieNode{
public:
    TrieNode* next[26];
    bool end;
    string str;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
        end = false;
        str = "";
    }
    ~TrieNode(){
        for(auto node:next){
            delete node;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie(){
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        curInsert(word, 0, root);
    }
    
    

private:
    
    void curInsert(string& word, int pos, TrieNode* tnode){
        if(pos < word.size()){
            if(!tnode->next[word[pos] - 'a']){
                tnode->next[word[pos] - 'a'] = new TrieNode();
            }
            curInsert(word, pos+1, tnode->next[word[pos] - 'a']);
        }
        else{
            tnode->end = true;
            tnode->str = word;
        }
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        m = board.size();
        if(m == 0)
            return res;
        n = board[0].size();
        Trie* myTrie = new Trie();
        for(auto word: words){
            myTrie->insert(word);
        }
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i = 0; i< m; i++){
            for(int j = 0; j <n ; j++){
                dfs(board, myTrie->root, i ,j, res, visited);
            }
        }
        // sort(res.begin(),res.end());
        return res;
    }

private:
    int m;
    int n;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    void dfs(vector<vector<char>>& board, TrieNode* root, int i, int j, vector<string>& res,vector<vector<bool>>& visited ){
        // cout<<i<<" "<<j<<" "<<endl;
        if(root->end){
            res.push_back(root->str);
            root->end = false;
        }
        if(i>=0 and i<m and j>=0 and j <n and !visited[i][j] and root->next[board[i][j] - 'a']){
            visited[i][j] = true;
            for(int k = 0; k < 4; k++){
                dfs(board, root->next[board[i][j] - 'a'], i+dx[k] ,j+dy[k], res, visited);
            }
            visited[i][j] = false;
        }
            
    }
};
