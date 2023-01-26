/*

-----leetcode ID :  https://leetcode.com/vishal1029/


391. Perfect Rectangle
Hard
745
108
Companies
Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.

 

Example 1:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.
Example 2:


Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.
Example 3:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.


*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mp;
        int ct=0; 
        for(auto P : rectangles){
 
            mp[{P[0],P[1]}]++;
            mp[{P[2],P[3]}]++;
            mp[{P[0],P[3]}]--;
            mp[{P[2],P[1]}]--;
            // cout<<endl; 
        } 
        for(auto itr : mp){
            
            ct+=abs(itr.second);
        }
        return ct==4;
 
    }
};
