/*


leetcode ID :  https://leetcode.com/vishal1029/


1358. Number of Substrings Containing All Three Characters
Medium
2.1K
35
Companies
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1

*/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int ind_a = -1;
        int ind_b = -1;
        int ind_c = -1;

        int i=0;
        int count = 0;
        for(auto x : s){
            if(x == 'a'){
                ind_a =  i;
            }
            else if(x == 'b'){
                ind_b = i;
            }
            else {
                ind_c = i;
            }
            
            if(i>0){
                count  += min(min(ind_a,ind_b),ind_c) + 1;
            }
            i++;
        }

        return count;
    }
};