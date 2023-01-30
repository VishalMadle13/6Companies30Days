

/*


leetcode ID :  https://leetcode.com/vishal1029/


792. Number of Matching Subsequences
Medium
4.9K
205
Companies
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2

*/





//bruteforce

// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
        
      
//         int wordsCount = 0;
//         for(auto x : words){
//             int j=0;
//             int c=0;
//             for(int i=0; i<x.size(); i++){
              
//                for( j = j; j<s.size(); j++){
//                    if(x[i] == s[j]){
//                        c++;
//                        break;
//                    }
//                }  
//                j++;
//             }
//             if(c == x.size()){
//                 wordsCount++;
//             }
//         }

//         return wordsCount;
//     }
// };


class Solution {
public:
  
	int numMatchingSubseq (string S, vector<string>& words) {
		vector<vector<int>> alpha (26);
		for (int i = 0; i < S.size (); ++i) alpha[S[i] - 'a'].push_back (i);
		int res = 0;

		for (const auto& word : words) {
			int x = -1;
			bool found = true;

			for (char c : word) {
				auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
				if (it == alpha[c - 'a'].end ()) found = false;
				else x = *it;
			}

			if (found) res++;
		}

		return res;
	}

};