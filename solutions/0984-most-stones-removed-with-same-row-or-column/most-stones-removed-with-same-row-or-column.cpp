// On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.
//
// Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
//
// What is the largest possible number of moves we can make?
//
//  
//
//
// Example 1:
//
//
// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
//
//
//
// Example 2:
//
//
// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
//
//
//
// Example 3:
//
//
// Input: stones = [[0,0]]
// Output: 0
//
//
//  
//
// Note:
//
//
// 	1 <= stones.length <= 1000
// 	0 <= stones[i][j] < 10000
//
//
//
//
//


// struct hash_pair { 
//     template <class T1, class T2> 
//     size_t operator()(const pair<T1, T2>& p) const
//     { 
//         auto hash1 = hash<T1>{}(p.first); 
//         auto hash2 = hash<T2>{}(p.second); 
//         return hash1 ^ hash2; 
//     } 
// }; 

// class Solution {
// public:

//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         unordered_set<pair<int,int>,hash_pair> points;
//         unordered_map<int, vector<int>> raws;
//         unordered_map<int, vector<int>> cols;
//         for(int i = 0; i < n; i++){
//             int r = stones[i][0];
//             int c = stones[i][1];
//             points.insert(make_pair(r, c));
//             raws[r].push_back(c);
//             cols[c].push_back(r);
//         }
//         int res = 0;
//         for(int i = 0; i <n; i++){
//             int r = stones[i][0];
//             int c = stones[i][1];
//             if(points.find(make_pair(r,c)) != points.end()){
//                 dfs(points, raws, cols, r,c);
//                 res++;
//             }
//         }
//         return stones.size() - res;
//     }
//     void dfs(unordered_set<pair<int,int>,hash_pair>& points, unordered_map<int, vector<int>>& raws, unordered_map<int, vector<int>>& cols, int r, int c){
//             points.erase(make_pair(r,c));
//             for(auto cc:raws[r]){
//                 if(points.find(make_pair(r,cc)) != points.end()){
//                     dfs(points, raws, cols, r,cc);
//                 }
//             }
//             for(auto rr:cols[c]){
//                 if(points.find(make_pair(rr,c)) != points.end()){
//                     dfs(points, raws, cols, rr,c);
//                 }
                    
//             }
//         }
// };c

class Solution {
public:
    unordered_map<int,int> f;
    int res = 0;
    int removeStones(vector<vector<int>>& stones) {
        for(int i = 0; i < stones.size();i++){
            uni(stones[i][0], ~stones[i][1]);
        }
        return stones.size() - res;
    }
    int find(int x){
        if(!f.count(x)){
            f[x] = x;
            res++;
            return x;
        }
        if(f[x]!=x){
            f[x] = find(f[x]);
        }
        return f[x];
    }
        
    void uni(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            f[fx] = fy;
            res--;
        }
    }
};
