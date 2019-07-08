// There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.
//
// Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
//
//
// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:
//
//
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
//
//
// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:
//
//
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
//
// Note:
//
//
// 	The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// 	The size of flights will be in range [0, n * (n - 1) / 2].
// 	The format of each flight will be (src, dst, price).
// 	The price of each flight will be in the range [1, 10000].
// 	k is in the range of [0, n - 1].
// 	There will not be any duplicated flights or self cycles.
//
//


class Solution {
public:
    struct compare{
        bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b){
            return get<1> (a) > get<1> (b);
        }    
    }; 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,compare> pq;
        vector<vector<int>> G(n,vector<int>(n,-1));
        for(auto flight:flights){
            G[flight[0]][flight[1]] = flight[2];
        }
        pq.push(make_tuple(src,0,K));
        while(!pq.empty()){
            int s = get<0> (pq.top());
            int dist = get<1> (pq.top());
            int k = get<2> (pq.top());
            // cout<<s<<" "<<dist<<" "<<pq.size()<<endl;
            pq.pop();
            if(s == dst)
                return dist;
            if(k >=0){
                for(int i = 0; i < n; i++){
                    // cout<<dist + G[s][i]<<endl;
                    if(G[s][i] > 0){
                        // cout<<dist + G[s][i]<<endl;
                        pq.push(make_tuple(i, dist + G[s][i], k-1));
                    }
                }
            }
        }
        return -1;
    }
};
