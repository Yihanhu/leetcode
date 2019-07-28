// Design a data structure that supports the following two operations:
//
//
// void addWord(word)
// bool search(word)
//
//
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
//
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
//
//
// Note:
// You may assume that all words are consist of lowercase letters a-z.
//


class TrieNode{
public:
    char c;
    bool isEnd;
    TrieNode* next[26] = {NULL};
    TrieNode(char input){
        c = input;
        isEnd = false;
    }

};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode(NULL);
        root->isEnd = true;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* ptr = root;
        for(int i =0; i < word.size();i++){
            char s = word[i];
            int pos = static_cast<int>(s - 'a');
            if(ptr->next[pos]){
                if(i == (word.size() - 1)){
                    ptr->next[pos]->isEnd = true;
                }
                ptr = ptr->next[pos];
            }
            else{
                ptr->next[pos] = new TrieNode(s);
                if(i == (word.size() - 1)){
                    ptr->next[pos]->isEnd = true;
                }
                ptr = ptr->next[pos];
            }
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, root);
    }
    
    bool searchHelper(string word, TrieNode* ptr){
        for(int i =0; i < word.size();i++){
            char s = word[i];
            if(s == '.'){;
                for(int j = 0; j < 26; j++){
                    if(ptr->next[j]){
                        if((word.size() - 1 - i) != 0){
                            if(searchHelper(word.substr(i+1, word.size() - 1 - i), ptr->next[j])){
                                return true;
                            }
                        }
                        else if(ptr->next[j]->isEnd)
                            return true;
                    }
                }
                return false;
            }
            int pos = static_cast<int>(s - 'a');
            if(ptr->next[pos]){
                if(i <= word.size() - 1){
                    ptr = ptr->next[pos];
                }
            }
            else{
               return false;
            }
        }
        return ptr->isEnd;
    }
// private:
    
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
