/*

leetcode ID :  https://leetcode.com/vishal1029/

1305. All Elements in Two Binary Search Trees
Medium
2.7K
78
Companies
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]


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
public:
    void getNodes(TreeNode* root,vector<int>& ans){
        if(root == NULL){
            return;
        }
          ans.push_back(root->val);
        if(root->left == NULL and root->right == NULL){
            return;
        } 
        getNodes(root->left,ans);
        getNodes(root->right,ans);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        getNodes(root1,ans);
        getNodes(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;

    }
};