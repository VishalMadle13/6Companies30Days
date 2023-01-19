/*
  
 
 * leetcode ID :  https://leetcode.com/vishal1029/
 
 
 368. Largest Divisible Subset
Medium
4.1K
167
Companies
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

 
*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int max = 1;
        vector<int> dp(n+1,1);
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i] = 1+dp[j];
                    if(max<dp[i])
                        max = dp[i];
                }
            }
        }
        for(auto x : dp){
            cout<<x<<" ";
        }

        int prev = -1;
         for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==max &&  (prev%nums[i]==0 || prev==-1))
            {
                ans.push_back(nums[i]);
                max -=1;
                prev = nums[i];
            }
        }
        return ans;

     
    }
};