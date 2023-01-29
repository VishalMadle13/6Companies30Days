/*

600. Non-negative Integers without Consecutive Ones
Hard
1.3K
122
Companies
Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

 

Example 1:

Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 


*/

// hard

class Solution {
public:
    int findIntegers(int n) { 
        return 1 + countValidInts(1, n);
    }
    
private:
    int countValidInts(int integer, int limit) { 
        if (integer > limit)  return 0;
        
        if (integer & 1)  return 1 + countValidInts((integer << 1) | 0, limit);
        else  return 1 + countValidInts((integer << 1) | 0, limit) + countValidInts((integer << 1) | 1, limit);
         
    }
};
// class Solution {
// public:
//     int findIntegers(int n) {
//         // add extra 1 for 0
//         // find the count of valid integers in the range [1, n]
//         return 1 + countValidInts(1, n);
//     }
    
// private:
//     int countValidInts(int integer, int limit) {
//         // do not add to total count if current integer exceeds limit
//         if (integer > limit) {
//             return 0;
//         }
        
//         if (integer & 1) {
//             // current integer ends with bit 1
//             // one option - append bit 0
            
//             // add 1 to count current valid integer
//             // add count of valid integers when appending 0 to current integer
            
//             return 1 + countValidInts((integer << 1) | 0, limit);
//         } else {
//             // current integer ends with bit 0
//             // two options - append bit 0 or bit 1
            
//             // add 1 to count current valid integer
//             // add count of valid integers when appending 0 to current integer and
//             // add count of valid integers when appending 1 to current integer
            
//             return 1 + countValidInts((integer << 1) | 0, limit) + countValidInts((integer << 1) | 1, limit);
//         }
//     }
// };
