/*
581. Shortest Unsorted Continuous Subarray
Medium
7.2K
245
Companies
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.


*/

// sorting method

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      
        vector<int> v(nums);
        int n = nums.size();
        
        sort(v.begin(),v.end());

        int start = v.size(), end = 0;
        for(int i=0; i<n; i++){
            if(v[i] != nums[i]){start = min(start,i); end = max(end,i);}
        }

        return end - start < 0 ? 0 : end-start + 1; 
    }
};
 
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         if(nums.size()==1){
//             return 0;
//         }
//         int p = 0,q = nums.size()-1;
//         for(int i=0; i<nums.size()-1; i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[j]<nums[i]){
//                     p = max(p,j);
//                     q = min(q,i);
//                 }
//             }
//         }

//         return p-q < 0 ?  0 : p-q+1;
//     }
// };
 