/*


leetcode ID :  https://leetcode.com/vishal1029/



2426. Number of Pairs Satisfying Inequality
Hard
353
6
Companies
You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.

 

Example 1:

Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
Output: 3
Explanation:
There are 3 pairs that satisfy the conditions:
1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
Therefore, we return 3.
Example 2:

Input: nums1 = [3,-1], nums2 = [-2,2], diff = -1
Output: 0
Explanation:
Since there does not exist any pair that satisfies the conditions, we return 0.


*/


//solution


class Solution {
public:
    // brute-force approach ::
    // long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    //     int n = nums1.size();
    //     long long c = 0;
    //     for(int i=0; i<n; i++){
    //         for(int j=i+1; j<n; j++){
    //             if((nums1[i] - nums1[j]) <= (nums2[i]-nums2[j]+diff)){
    //                 c++;
    //             }
    //         }
    //     }
    //     return c;
    // }
    
    
    
    long long c = 0;
    void checkCount(vector<int>&num,int start,int mid,int end,int diff){
        int l=start,r=mid+1;
        while(l<=mid and r<=end){
            if(num[l]<=num[r]+diff){
                c += (end-r+1);
                l++;
            }
            else{
                r++;
            }
        }
        sort(num.begin() + start, num.begin() + end + 1);  // (Sort using two-pointers for better time complexity)
        return;
    }
    void mergeSort(vector<int>&num,int start,int end,int diff){
        // int mid = (start+end)/2;
        if(start == end){
            return;
        }
        int mid = start + (end-start)/2;
        mergeSort(num,start,mid,diff);
        mergeSort(num,mid+1,end,diff);
        checkCount(num,start,mid,end,diff);
        return;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> num;
        for(int i=0; i<n; i++){
            num.push_back(nums1[i]-nums2[i]);
        } 
        mergeSort(num,0,n-1,diff);
        return c;
    }
};