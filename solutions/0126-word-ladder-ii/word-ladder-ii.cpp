// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return an empty list if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]
//
//
// Example 2:
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: []
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
public:
    bool isConnect(string &word1, string &word2){
        int diff_count = 0;
        for (int i = 0;i<word1.length();i++ ){
            if (word1[i] != word2[i]){
                diff_count++;
            }
        }
        return diff_count == 1;
    }
    
    void build_graph(unordered_map<string , vector<string>> & graph,vector<string>& wordList){
        for (int i = 0; i < wordList.size() ; i++){
            graph[wordList[i]] = vector<string> ();
        }
        for (int i = 0; i < wordList.size() ; i++){
            for (int j = i + 1; j < wordList.size() ; j++){
                // cout<<isConnect(wordList[i], wordList[j])<<endl;
                if (isConnect(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string , vector<string>> graph;
        unordered_map<string , int> visit;
        if (find(wordList.begin(),wordList.end(),beginWord) == wordList.end()){
            wordList.push_back(beginWord);   
        }
        build_graph(graph, wordList);
        vector<int> endWordList;
        vector<vector<string>> result;
        for (int i =0 ; i <wordList.size(); i++){
            visit[wordList[i]] = 0;
        }
        vector<tuple<string,int,int>> Q;
        Q.push_back(std::make_tuple(beginWord,1,-1));
        int Q_front = 0;
        visit[beginWord] = 1;
        while(Q_front<Q.size()){
            string word;
            int step;
            int front;
            std::tie (word , step , front) = Q[Q_front];
            // cout<<word << step << front<<endl;
            vector<string> neighbor = graph[word];
            for (int i =0; i < neighbor.size() ; i++){
                if (visit[neighbor[i]] ==step + 1|visit[neighbor[i]] == 0){
                    // cout<<neighbor[i]<<neighbor.size()<<endl;
                    Q.push_back(make_tuple(neighbor[i],step+1,Q_front));
                    visit[neighbor[i]] = step + 1;
                    if (neighbor[i] == endWord){
                        endWordList.push_back(Q_front);
                    }
                }
            }
            Q_front++;
        }
        if (endWordList.size() == 0){
            return result;
        }
        else{
            string word;
            int step;
            int front;
            while(!endWordList.empty()){
                int front_int = endWordList.back();
                endWordList.pop_back();
                vector<string> tmp_result;
                tmp_result.push_back(endWord);
                while(front_int != -1){
                    std::tie (word , step , front_int) = Q[front_int];
                    // cout<<word<<step<<' '<<front_int;
                    tmp_result.push_back(word);
                }
                vector<string> rev_result;
                while(!tmp_result.empty()){
                    rev_result.push_back(tmp_result.back());
                    tmp_result.pop_back();
                }
                result.push_back(rev_result);
            }           
        }
        return result;
    }
};
