/*

334. Increasing Triplet Subsequence
Medium
6.2K
269
Companies
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

*/

// class Solution{
//     public:
//     bool increasingTriplet(vector<int>& nums){
        
//         int mn = INT_MAX, mx = INT_MAX;
//         for(auto x : nums){
//             if(x > mx ) return true;
//             if(x > mn) mx = min(mn,x);
//             mn = min(mn,x);
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a = 1e10, b = 1e10;
        for (int i : nums) {
            if (i > b) return true;
            if (i > a) b = min((long long) i, b);
            a = min((long long) i, a);
        }
        return false;
    }
};
// bruteforce approach

// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n = nums.size();
//         int mn  = nums[0], mx = nums[n-1];
//         for(int i=1; i<n-1; i++){
//             int p = i;
//             while(p >= 0){
//                 mn = min(mn,nums[p]);
//                 p--;
//             }
//             p = i;
//             while(p < n){
//                 mx = max(mx,nums[p]);
//                 p++;
//             }
//             if(nums[i] > mn and nums[i] < mx )return true;
//         } 
//         return false;
//     }
// };