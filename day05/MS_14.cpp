/*


leetcode ID :  https://leetcode.com/vishal1029/



2344. Minimum Deletions to Make Array Divisible
Hard
442
109
Companies
You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.

Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.

Note that an integer x divides y if y % x == 0.

 

Example 1:

Input: nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
Output: 2
Explanation: 
The smallest element in [2,3,2,4,3] is 2, which does not divide all the elements of numsDivide.
We use 2 deletions to delete the elements in nums that are equal to 2 which makes nums = [3,4,3].
The smallest element in [3,4,3] is 3, which divides all the elements of numsDivide.
It can be shown that 2 is the minimum number of deletions needed.
Example 2:

Input: nums = [4,3,6], numsDivide = [8,2,6,10]
Output: -1
Explanation: 
We want the smallest element in nums to divide all the elements of numsDivide.
There is no way to delete elements from nums to allow this.
 

Constraints:

1 <= nums.length, numsDivide.length <= 105
1 <= nums[i], numsDivide[i] <= 109


*/



// method 3 - using gcd 
// optimized approach 


class Solution {
public:
    int gcd(int a,int b)
    {
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        for(int i=0;i<numsDivide.size();i++)
        {
            g=gcd(g,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && nums[i]<=g;i++)
        {
            if(g%nums[i]==0)
            {
                return i;
            }
}
        return -1;
        
        
    }
};


//   method - method 2
//   optimized approach than method 1 -- frequency map


// class Solution {
// public:
//     int minOperations(vector<int>& nums, vector<int>& numsDivide) {

//         map<long long,int> mp1;
//         unordered_map<long long,int> mp2;

//         for(auto x : nums){
//             mp1[x]++;
//         }
//         for(auto x : numsDivide){
//             mp2[x]++;
//         }



//         for( auto  x : mp2){
//             cout<<x.first<<" "<<x.second<<endl;
//         }




//         int deletion = 0;
//         for(auto x :mp1){
//             int c = 0;
//             for(auto y : mp2){
//                 if(y.first % x.first != 0){
//                     break;
//                 }
//                 c++;
//             }
//             cout<<c<<" ";
//             if(c == mp2.size()){
//                 return deletion;
//             }
//             deletion += x.second;
//         }
//         return -1;
//     }
// };

// // simple method - method 1  -- by sorting the nums vector
// // do as given in question with pointer approach 
//  TLE will occure for large size of nums and numsDivide

// class Solution {
// public:
//     int minOperations(vector<int>& nums, vector<int>& numsDivide) {
//         int min_num;
//         int n = nums.size();
        
//         sort(nums.begin(),nums.end());
//         int deletions = 0;
//         int  count;
    
//         for(int i=0; i<n; i++){
//            count = 0;
            
//             for(auto x : numsDivide){
//                 if(x%nums[i] == 0){
//                      count++;
//                 }
//             }
              
//             cout<<count<<" ";
//             if(count == numsDivide.size()){
//                 return deletions;
//             }
//             deletions++;
//         }
          

//         return -1; 
//     }
// };