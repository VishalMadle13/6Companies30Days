/*

1814. Count Nice Pairs in an Array
Medium
681
27
Companies
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4

*/


// method 2 : optimized approach  ||  using map
// 
class Solution {
public:
    int rev(int num){
        int temp = 0;
      
        while(num > 0){
            int rem = num%10;
            temp = temp*10 + rem;    //   // 123 //  3 -- 30 + 2 -- 320  +1
            num = num/10;
        }
        return temp;
    }

    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        int mod = 1e9+7;
        vector<int> revnums(nums.size());
        unordered_map<int,int> mpp;         // {  key : val  }   ==>      {  diff(nums[i] - rev(nums[i]))   : frequency  }
        for(int i= 0; i<nums.size(); i++){
           revnums[i] = rev(nums[i]);
        }
    
        for(auto x : revnums ){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x : nums ){
            cout<<x<<" ";
        }
        cout<<endl;
        for(int i =0 ; i<nums.size(); i++){
            cout<<"X";
           if(mpp.find(nums[i] - revnums[i]) != mpp.end()){       // element with  difference(x - rev(x)) found
                count += (mpp[nums[i] - revnums[i]])%mod;
                count %= mod;
           }
            
               mpp[  nums[i] - revnums[i]  ]++;
          
        // mpp[  nums[i] - revnums[i]  ]++;
        }
        
        for(auto x: mpp){
            cout<<x.first<<" "<<x.second<<endl;
        }
        return count%mod;
    }
};



// method 1  : bruteforce approach

// class Solution {
// public:
//     int rev(int num){
//         int temp = 0;
      
//         while(num > 0){
//             int rem = num%10;
//             temp = temp*10 + rem;    //   // 123 //  3 -- 30 + 2 -- 320  +1
//             num = num/10;
//         }
//         return temp;
//     }

//     int countNicePairs(vector<int>& nums) {
//         long long count = 0;
//         int mod = 1000000007;
//         vector<int> revnums(nums.size());
//         for(int i= 0; i<nums.size(); i++){
//              cout<<rev(nums[i])<<" ";
//            revnums[i] = rev(nums[i]);
//         }
//         cout<<endl;
    

//         for(int i =0 ; i<nums.size(); i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i] + revnums[j] == nums[j] + revnums[i]){
//                     count++;
//                 }
//             }
//         }
       
//         return count%mod;
//     }
// };