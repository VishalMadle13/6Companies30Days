/*

leetcode ID :  https://leetcode.com/vishal1029/

447. Number of Boomerangs
Medium
722
942
Companies
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

 

Example 1:

Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].


*/

class Solution {
public:
    double dist(vector<int> p1,vector<int> p2){
        double x = pow(p2[0]-p1[0],2); 
        double y = pow(p2[1]-p1[1],2); 
        return sqrt(x+y);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {\
        if(points.size()<3){
            return 0;
        }
        int sum = 0;
        unordered_map<double,int> mpp;
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                if(i!=j){
                    double x = dist(points[i] , points[j]);
                    mpp[x]++; 
                } 
            }
            for(auto x : mpp){
                // cout<<x.first<<" "<<x.second<<endl;
                if(x.second > 1){
                     sum += x.second*(x.second-1);
                } 
            } 
           
            mpp.clear();
        }
    
    

        return sum;;
    }
};