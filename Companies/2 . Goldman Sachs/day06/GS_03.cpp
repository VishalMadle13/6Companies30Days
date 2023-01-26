/*

leetcode ID :  https://leetcode.com/vishal1029/

172. Factorial Trailing Zeroes
Medium
2.5K
1.8K
Companies
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0

*/

class Solution {
public:
    int trailingZeroes(int n) {
     int sum = 0;

     while(n>0){    
            sum += n/5;                 // n/5 gives us  the count of factor 5 in number  
            n = n/5;
    } 
    return sum;
    }
};