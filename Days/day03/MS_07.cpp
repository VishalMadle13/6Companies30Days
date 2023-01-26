/*


leetcode ID :  https://leetcode.com/vishal1029/


207. Course Schedule
Medium
12.5K
484
Companies
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.



*/



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create an adjacency list
        unordered_map<int,list<int>> adj;
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        //step 1 : find indegree for each node
        vector<int> indegree(numCourses);
        
        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++;
            }
        }

        //step 2 : add elements with indegree = 0 to a queue
        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        //step 3 : apply BFS
        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            //update indegree of the neighbours
            for(auto i : adj[front]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        //step 4 : Finally if indegree all the nodes = 0, then return true.
        if(ans.size() == numCourses)
            return true;
        else
            return false; 
    }
};