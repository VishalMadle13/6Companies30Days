/*


leetcode ID :  https://leetcode.com/vishal1029/

1878. Get Biggest Three Rhombus Sums in a Grid
Medium
159
452
Companies
You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

 

Example 1:


Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
Example 2:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
Example 3:

Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].

*/

class Solution {
public:
    bool isvalid(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int>s;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                s.insert(grid[i][j]);
            }
        }
        for(int i=1; i<=50; i++){
            for(int j=0; j<grid.size(); j++){
                for(int k=0; k<grid[0].size(); k++){
                    if(isvalid(j-i, k, grid.size(), grid[0].size()) && isvalid(j, k-i, grid.size(), grid[0].size()) && isvalid(j+i, k, grid.size(), grid[0].size()) && isvalid(j, k+i, grid.size(), grid[0].size())){
                        int sum=grid[j-i][k]+grid[j+i][k]+grid[j][k-i]+grid[j][k+i];
                        for(int x=1; x<i; x++){
                            sum+=grid[j-x][k+i-x];
                        }
                        for(int x=1; x<i; x++){
                            sum+=grid[j-x][k-i+x];
                        }
                        for(int x=1; x<i; x++){
                            sum+=grid[j+x][k+i-x];
                        }
                        for(int x=1; x<i; x++){
                            sum+=grid[j+x][k-i+x];
                        }
                        s.insert(sum);
                    }
                }
            }
        }
        vector<int>v;
        for(auto it: s){
            v.push_back(it);
        }
        reverse(v.begin(), v.end());
        vector<int>ans;
        if(v.size()<3){return v;}
        for(int i=0; i<3; i++){ans.push_back(v[i]);}
        return ans;
    }
};


