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


class TrieNode {
public:
    TrieNode * next[26];
    bool is_word;
    TrieNode(bool b = false){
        memset(next,0,sizeof(next));
        is_word = b;
    }
};


class Trie {
    TrieNode * head;
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode();        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ptr = head;
        for (auto c : word){
            short num = c - 'a';
            // cout<<c;
            if(!ptr->next[num]){
                ptr->next[num] = new TrieNode();
            }
            ptr = ptr->next[num];
        }
        ptr->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ptr = head;
        for(auto c: word){
            short num = c - 'a';
            if(!ptr->next[num]){
                return false;
            }
            ptr = ptr->next[num];
        }
        return ptr->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ptr = head;
        for(auto c: prefix){
            short num = c - 'a';
            if(!ptr->next[num]){
                return false;
            }
            ptr = ptr->next[num];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
