/*



leetcode ID :  https://leetcode.com/vishal1029/



2260. Minimum Consecutive Cards to Pick Up
Medium
591
17
Companies
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

 

Example 1:

Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
Example 2:

Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.
 

 
*/



// method 2 - using map

#include<bits/stdc++.h>

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int,int> mpp;     // map< key :  last_Index  >

        int i=0;
        int mn = INT_MAX;
        for(auto x : cards){
            
            if(mpp.find(x) != mpp.end()){       // element is found
                mn = min(mn,i-mpp[x] +1);
              
            } 
            mpp[x] = i;  
            i++;
        }
   
        if(mn == INT_MAX){
            mn = -1;
        }
        return mn;
    }
};

 

// method 1 - bruteforce approach
// class Solution {
// public:
//     int minimumCardPickup(vector<int>& cards) {
//         int n = cards.size();
//         int mx = INT_MAX;
//         cout<<mx<<endl;
//         for(int i=0; i<n; i++){

//             for(int j=i+1; j<n; j++){
//                 if(cards[i] == cards[j]){
//                     mx = min(mx,j-i+1);
//                 } 
//             }
//         }
//         if(mx == INT_MAX){
//             mx = -1;
//         }

//         cout<<mx;
//         return mx;
//     }
// };