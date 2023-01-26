/*


leetcode ID :  https://leetcode.com/vishal1029/



2179. Count Good Triplets in an Array
Hard
488
20
Companies
You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

 

Example 1:

Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation: 
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
Example 2:

Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
 

Constraints:

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 and nums2 are permutations of [0, 1, ..., n - 1].

*/

class Solution {
public:
    // function to return the last bit set in the input number
    inline int lastOne(int x) {
        return x & (-x);
    }
    
    // function to update a Fenwick tree with delta at index i
    void updateFenwickTree(vector<int>& fenwickTree, int index, int delta) {
        for(;index < fenwickTree.size(); index += lastOne(index)) {
            fenwickTree[index] += delta; 
        }
    }
    
    // function to get the prefix sum of the Fenwick tree up to index i
    int getPrefixSum(vector<int>& fenwickTree, int index) {
        int prefixSum = 0; 
        for(;index;index -= lastOne(index)) {
            prefixSum += fenwickTree[index];
        }
        return prefixSum; 
    }
    
    // function to get the range sum of the Fenwick tree between startIndex and endIndex
    int getRangeSum(vector<int>& fenwickTree, int startIndex, int endIndex) {
        return getPrefixSum(fenwickTree,endIndex) - (startIndex == 1?0:getPrefixSum(fenwickTree,startIndex-1));
    }
    
    // main function to find good triplets
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        // get the size of the input vectors
        const int vectorSize = nums1.size(); 
        // create a vector to hold the index positions of nums1
        vector<int> indexPositions(vectorSize);
        for(int i = 0; i < vectorSize; i++) {
            indexPositions[nums1[i]] = i;
        }
        // variable to count the number of good triplets
        long long goodTripletCount = 0; 
        // create a Fenwick tree with size n + 5
        vector<int> fenwickTree(vectorSize + 5);
        // create a vector to hold the number of elements smaller than nums2[i] in nums1 to the right of nums1[i]
        vector<int> smallerElementsToRight(vectorSize);
        // loop through nums2 backwards
        for(int i = vectorSize - 1; i >= 0; i--) {
            // get the index position of nums2[i] in nums1
            int index = indexPositions[nums2[i]];
            // store the number of elements smaller than nums2[i] in nums1 to the right of nums1[i]
            smallerElementsToRight[nums2[i]] = getRangeSum(fenwickTree,index + 1,vectorSize + 1);
            // update the Fenwick tree at index j + 1
            updateFenwickTree(fenwickTree,index + 1,1);
        }
        // reset the Fenwick tree
        fenwickTree.assign(vectorSize + 5,0);
        // loop through nums2 forwards
        for(int i = 0; i < vectorSize; i++) {
            // get the index position of nums2[i] in nums1
            int index = indexPositions[nums2[i]];
            // count the number of good triplets using the stored values
            long long smallerElementsBefore = getPrefixSum(fenwickTree,index);
            goodTripletCount += smallerElementsBefore * smallerElementsToRight[nums2[i]];
            // update the Fenwick tree at index j + 1
            updateFenwickTree(fenwickTree,index + 1,1);
        }
    return goodTripletCount;
    }
};