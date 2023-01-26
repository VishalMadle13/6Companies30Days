/*

leetcode ID :  https://leetcode.com/vishal1029/

2212. Maximum Points in an Archery Competition
Medium
397
38
Companies
Alice and Bob are opponents in an archery competition. The competition has set the following rules:

Alice first shoots numArrows arrows and then Bob shoots numArrows arrows.
The points are then calculated as follows:
The target has integer scoring sections ranging from 0 to 11 inclusive.
For each section of the target with score k (in between 0 to 11), say Alice and Bob have shot ak and bk arrows on that section respectively. If ak >= bk, then Alice takes k points. If ak < bk, then Bob takes k points.
However, if ak == bk == 0, then nobody takes k points.
For example, if Alice and Bob both shot 2 arrows on the section with score 11, then Alice takes 11 points. On the other hand, if Alice shot 0 arrows on the section with score 11 and Bob shot 2 arrows on that same section, then Bob takes 11 points.

You are given the integer numArrows and an integer array aliceArrows of size 12, which represents the number of arrows Alice shot on each scoring section from 0 to 11. Now, Bob wants to maximize the total number of points he can obtain.

Return the array bobArrows which represents the number of arrows Bob shot on each scoring section from 0 to 11. The sum of the values in bobArrows should equal numArrows.

If there are multiple ways for Bob to earn the maximum total points, return any one of them.

 

Example 1:


Input: numArrows = 9, aliceArrows = [1,1,0,1,0,0,2,1,0,1,2,0]
Output: [0,0,0,0,1,1,0,0,1,2,3,1]
Explanation: The table above shows how the competition is scored. 
Bob earns a total point of 4 + 5 + 8 + 9 + 10 + 11 = 47.
It can be shown that Bob cannot obtain a score higher than 47 points.



*/


class Solution {
public:
vector<int>ans;//answer array 
int maxpoints=0; //stores the maximum points by bob
    void solve(int ind,int score,int arrow,vector<int> &nums,vector<int> &res){
        if(arrow==0||ind<0){
            //if ind goes negitive or arrows count became 0.
            //Then check if current score is the maximum score .
            //If score is maximum the res array is ans array.
            if(score>maxpoints){
                maxpoints=score;
                ans=res;
            }
            return ;
        }
        //if available arrows is greater than the arrorws requires for the current score index then we can take this score.
        if(arrow>nums[ind]){
           res[ind]=nums[ind]+1;
            solve(ind-1,score+ind,arrow-(nums[ind]+1),nums,res);//taking the current index score.
          res[ind]=0;
           
        }
        //Here we are not taking the current index score.
        solve(ind-1,score,arrow,nums,res);
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>res(12,0);//To store the values of arrows used by bob
        solve(11,0,numArrows,aliceArrows,res);
        int cnt=0;
        for(auto it:ans){
            cnt+=it;

        }
        int startind=numArrows-cnt;
        if(startind>0){
            ans[0]+=startind;
        }
         return ans;
    }
};