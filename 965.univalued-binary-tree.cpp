/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
 *
 * https://leetcode.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (69.69%)
 * Likes:    1640
 * Dislikes: 61
 * Total Accepted:    189K
 * Total Submissions: 271.2K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * A binary tree is uni-valued if every node in the tree has the same value.
 * 
 * Given the root of a binary tree, return true if the given tree is
 * uni-valued, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,1,1,1,1,null,1]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,2,2,5,2]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 100].
 * 0 <= Node.val < 100
 * 
 * 
 */

// @lc code=start
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
    void preorder(TreeNode*root,vector<int>&path){
        if(root==NULL) return;
        path.push_back(root->val);
        preorder(root->left,path);
        preorder(root->right,path);
    }
    bool helper(TreeNode*root,int rootData){
        if(root == NULL) return 1;
        if(root->val != rootData) return 0;
        bool left = helper(root->left,rootData);
        bool right = helper(root->right,rootData);
        bool ans = left && right;
        return ans;
    }
    bool isUnivalTree(TreeNode* root) {
        // ! Approach 1 : Useing iterative
        /* if(root==NULL) return 1;
        vector<int> path;
        preorder(root,path);
        * If there is only one node in the tree, then it's a univalued tree
        if(path.size()==1) return 1;
        * Check if all values stored in the path are same, if not then it's not a univalued tree
          for(int i=0; i<=path.size()-2;i++){
            if(path[i] != path[i+1]){
                return 0;
            }
        }
        * If all values stored in path are same, then it's a univalued tree
        return 1; */
    // ! Approach 2 : Using Recursive
    return helper(root,root->val);
    }
    
};
// @lc code=end

