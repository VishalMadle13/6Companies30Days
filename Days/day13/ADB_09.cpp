/*



leetcode ID :  https://leetcode.com/vishal1029/



2265. Count Nodes Equal to Average of Subtree
Medium
961
22
Companies
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
 
 


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
    int dfs(TreeNode* root, int &sum, int &count){
        if(root == NULL){
            sum = 0, count = 0;
            return 0;
        }

        int sum1 = 0, count1 = 0, sum2 = 0, count2 = 0;
        int ans1 = dfs(root->left, sum1, count1);
        int ans2 = dfs(root->right, sum2, count2);

        int ans = ans1+ans2;
        sum = sum1+sum2+root->val;
        count = count1+count2+1;
        int avg = (sum/(double)count);

        if(avg == root->val)
            ans++;

        return ans;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int sum, count;

        return dfs(root, sum, count);
    }
};
   