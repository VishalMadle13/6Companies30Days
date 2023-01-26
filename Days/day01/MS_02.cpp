
/*

leetcode ID :  https://leetcode.com/vishal1029/



216. Combination Sum III
Medium
4.6K
93
Companies
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.





*/

class Solution {
public:

    void solve(int ind, int sum, vector<vector<int>>& ans, vector<int>& temp, int k, int& n){
        if(sum == n and k==0){
            ans.push_back(temp);
            return;
        }
        if(sum>n){
            return;
        }
        for(int i=ind; i<=9; i++){
            if(i>n){
                
                break;
            }
            temp.push_back(i);
      
            solve(i+1,sum+i,ans,temp,k-1,n);
            temp.pop_back();
        }
        
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,0,ans,temp,k,n);
        return ans;
        
    }
};