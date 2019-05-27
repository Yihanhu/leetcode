// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
//
//
// Note:
//
//
// 	You may assume that all inputs are consist of lowercase letters a-z.
// 	All inputs are guaranteed to be non-empty strings.
//
//


class TrieNode{
public:
    TrieNode* next[26];
    bool end;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
        end = false;
    }
    ~TrieNode(){
        for(auto node:next){
            delete node;
        }
    }
};

class Trie {
public:
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return curSearch(word, 0, root);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return curStartswith(prefix, 0, root);
    }

private:
    TrieNode* root;
    
    void curInsert(string& word, int pos, TrieNode* tnode){
        if(pos < word.size()){
            if(!tnode->next[word[pos] - 'a']){
                tnode->next[word[pos] - 'a'] = new TrieNode();
            }
            curInsert(word, pos+1, tnode->next[word[pos] - 'a']);
        }
        else{
            tnode->end = true;
        }
    }
    
    bool curSearch(string& word, int pos, TrieNode* tnode){
        if(pos == word.size()){
            return tnode->end;
        }
        else{
            if(!tnode->next[word[pos] - 'a']){
                return false;
            }
            return curSearch(word, pos+1, tnode->next[word[pos] - 'a']);
        }
    }
    
    bool curStartswith(string& prefix, int pos, TrieNode* tnode){
        if(pos == prefix.size()){
            return true;
        }
        if(!tnode->next[prefix[pos] - 'a']){
            return false;
        }
        return curStartswith(prefix, pos+1, tnode->next[prefix[pos] - 'a']);
    }
};




/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
