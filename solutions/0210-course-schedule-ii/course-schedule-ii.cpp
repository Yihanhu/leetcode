// There are a total of n courses you have to take, labeled from 0 to n-1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
//
// Example 1:
//
//
// Input: 2, [[1,0]] 
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
//              course 0. So the correct course order is [0,1] .
//
// Example 2:
//
//
// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
//
// Note:
//
//
// 	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// 	You may assume that there are no duplicate edges in the input prerequisites.
//
//


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> zeros_pre;
        vector<int> res;
        vector<int> nums_pre(numCourses,0);
        vector<vector<int>> pre_tab;
        vector<int> visited (numCourses,0);
        for(int i =0 ; i<numCourses; i++){
            vector<int> tmp;
            pre_tab.push_back(tmp);
        }
        for(int i = 0; i< prerequisites.size();i++){
            int course = prerequisites[i].first;
            int pre = prerequisites[i].second;
            nums_pre[course]++;
            pre_tab[pre].push_back(course);
        }
        for(int i =0;i<nums_pre.size();i++){
            if (nums_pre[i] == 0){
                zeros_pre.push_back(i);
            }
        }
        while(zeros_pre.size()>0){
            int zero = zeros_pre.back();
            zeros_pre.pop_back();
            res.push_back(zero);
            for(int i = 0; i<pre_tab[zero].size();i++){
                int course = pre_tab[zero][i];
                nums_pre[course]--;
                if (nums_pre[course] == 0){
                    zeros_pre.push_back(course);
                }
            }
        }
        if (res.size() == numCourses){
            return res;    
        }
        else{
            vector<int> tmp;
            return tmp;
        }
        
    }
};
