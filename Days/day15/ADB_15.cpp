

/*
2343. Query Kth Smallest Trimmed Number
Medium
210
355
Companies
You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

Trim each number in nums to its rightmost trimi digits.
Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
Reset each number in nums to its original length.
Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

Note:

To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
Strings in nums may contain leading zeros.
 

Example 1:

Input: nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
Output: [2,2,1,0]
Explanation:
1. After trimming to the last digit, nums = ["2","3","1","4"]. The smallest number is 1 at index 2.
2. Trimmed to the last 3 digits, nums is unchanged. The 2nd smallest number is 251 at index 2.
3. Trimmed to the last 2 digits, nums = ["02","73","51","14"]. The 4th smallest number is 73.
4. Trimmed to the last 2 digits, the smallest number is 2 at index 0.
   Note that the trimmed number "02" is evaluated as 2.

*/
// method 01 

// class Solution {
// public:
    
//     string trimToLastDigit(string str, int lastdigits ){
//         string result = "";
//         for(int i=str.size()-1; lastdigits>0 ; i--){lastdigits--; result = str[i] + result;}
//         return result;
//     }
//     vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
//         vector<int> ans;  
//         for(auto q : queries){
//             // // q[0] --> lastdigit
//             // // q[1] --> q[1]th smallest element  --> kth
//             int lastdigit = q[1];
//             int k         = q[0];
          
//             int i=0;
//             vector<pair<string ,int>> v;   // [{number,index}];
//             for(auto x : nums)
//             {
//                string str =  trimToLastDigit(x,lastdigit); 
//                v.push_back({str,i});
//                i++;
//             }
//             sort(v); 
//             ans.push_back(v[k-1].second);
//         }

//         return ans; 
//     }
// };
    


class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto q: queries){
            int trim= q[1];
            int k= q[0];
            priority_queue<pair<string,int>> pq;
            for (int i=0; i<nums.size(); i++){
                string  val= nums[i];
                if (trim< nums[i].size()) val= nums[i].substr(nums[i].size()-trim,trim);

                pair<string,int> val1= {val,i};
                if (pq.size()<k){
                    pq.push(val1);
                }
                else{
                    if (val1 < pq.top()){
                        pq.pop();
                        pq.push(val1);
                    }
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};