// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
//
// Note:
//
//
// 	If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// 	All airports are represented by three capital letters (IATA code).
// 	You may assume all tickets form at least one valid itinerary.
//
//
// Example 1:
//
//
// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
//
//
// Example 2:
//
//
// Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
//              But it is larger in lexical order.
//
//


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res; 
        unordered_map<string, multiset<string>> map;
        for(int i = 0; i < tickets.size();i++){
            map[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs(map, "JFK",res);
        return vector<string> (res.rbegin(), res.rend());
    }
    
    void dfs(unordered_map<string, multiset<string>>& map, string s, vector<string>& res ){
        while(!map[s].empty()){
            string t = *map[s].begin();
            map[s].erase(map[s].begin());
            dfs(map, t, res);
        }
        res.push_back(s);
    }
};
