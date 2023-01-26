/*


leetcode ID :  https://leetcode.com/vishal1029/



1392. Longest Happy Prefix
Hard
966
30
Companies
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

*/


class Solution {
public:
    string longestPrefix(string s) {
        
       string ans="";
        vector<int>pos(s.size(), 0);
        int i=0, j=1;
        while(j<s.size()){
            if(s[i]==s[j]){
                pos[j]=i+1;
                i++;
                j++;
            }
            else if(i){
                i=pos[i-1];
            }
            else{
                j++;
            }
        }
        ans=s.substr(0, i);
        return ans;
    }
};