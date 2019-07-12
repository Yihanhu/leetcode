// There are N network nodes, labelled 1 to N.
//
// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
//
// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
//
//  
//
// Example 1:
//
//
//
//
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
// Output: 2
//
//
//  
//
// Note:
//
//
// 	N will be in the range [1, 100].
// 	K will be in the range [1, N].
// 	The length of times will be in the range [1, 6000].
// 	All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
//
//


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  pq;
        pq.push(make_pair(0,K));
        vector<vector<pair<int,int>>> G(N+1,vector<pair<int,int>>{});
        for(int i = 0; i< times.size();i++){
            int src = times[i][0];
            int dst = times[i][1];
            int w = times[i][2];
            G[src].push_back(make_pair(w,dst));
        }
        vector<int> res(N+1,INT_MAX);
        unordered_set<int> closed;
        res[K] = 0;
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            // cout<<dist<<" "<<node<<endl;
            pq.pop();
            if(closed.count(node))
                continue;
            closed.insert(node);
            res[node] = dist;
            cout<<closed.count(3)<<endl;
            for(int i =0;i<G[node].size();i++){
                if((G[node][i].first + dist) < res[G[node][i].second] and !closed.count(G[node][i].second)){
                    pq.push(make_pair(G[node][i].first + dist, G[node][i].second));
                }
            }
        }
        int max_num = INT_MIN;
        for(int i = 1; i < N+1; i++){
            max_num = max(max_num, res[i]);
        }
        return max_num == INT_MAX?-1:max_num;
        
    }
};
