/*

1975. Maximum Matrix Sum
Medium
446
18
Companies
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:


Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.


*/


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int countNegative = 0;
        long long sum = 0;
        bool zero = false;
        int mxN = INT_MIN;        // maximum negative number 
        int mnP = INT_MAX;
        for(auto x : matrix){
            for(auto e : x){
                if(e == 0){
                    zero = true;
                }
                sum += abs(e);
                if(e<0){
                    countNegative++;
                    mxN = max(mxN,e);
                }
                else{
                    mnP = min(mnP,e);
                }
            }
        }
        if(abs(mxN) > mnP){
            mxN = mnP*(-1);
        }
        if(countNegative%2 == 0 || zero){
            return sum;
        }

        return sum + 2*mxN;
    }
};