/*


leetcode ID :  https://leetcode.com/vishal1029/



1976. Number of Ways to Arrive at Destination
Medium
1.7K
57
Companies
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.

*/


class Solution {
public:
  
     int countPaths(int n, vector<vector<int>>& r) {
        int mod=1e9+7;
        vector<vector<pair<long long,long long>>>adj(n);
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
            adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        vector<long long>c(n,0);
        c[0]=1;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        vector<long long int>dist(n,1e15);
        dist[0]=0;
        pq.push({0,0});
        while(pq.empty()==false){
            auto x=pq.top();
            long long dis=x.first;
            long long node=x.second;
            pq.pop();
            for(auto it:adj[node]){
                long long wt=it.second;
                long long y=it.first; 
                if(wt+dis<dist[y]){
                    dist[y]=(wt+dis);
                    pq.push({dist[y],y});
                    c[y]=c[node];
                }
                else if((wt+dis)==dist[y]){
                    c[y]=(c[y]+c[node])%mod;
                }
                
            }
        }
        return c[n-1];
    }
};