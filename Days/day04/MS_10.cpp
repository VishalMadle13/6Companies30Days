/*

leetcode ID :  https://leetcode.com/vishal1029/



581. Shortest Unsorted Continuous Subarray
Medium
7.1K
246
Companies
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0




*/


// sorting method

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v;
        v = nums;
        sort(v.begin(),v.end());
        for(auto x :v){
            cout<<x<<" ";
        }
        int start = v.size(), end = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] != nums[i]){
                start = min(start, i);
                end   = max(end,i);
            }
        }

        return end - start < 0 ? 0 : end - start+1;
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
 