/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (67.61%)
 * Likes:    2949
 * Dislikes: 67
 * Total Accepted:    251.5K
 * Total Submissions: 372K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n' +
  '[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree, from left to right order, the
 * values of those leaves form a leaf value sequence.
 * 
 * 
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 * 
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
 * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [1,2,3], root2 = [1,3,2]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each tree will be in the range [1, 200].
 * Both of the given trees will have values in the range [0, 200].
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
    void getlefaDataRoot1(TreeNode* root1,vector<int> &path1){
        if(root1==nullptr) return ;
        if(root1->left==NULL && root1->right==NULL){
            path1.push_back(root1->val);
        }
        getlefaDataRoot1(root1->left,path1);
        getlefaDataRoot1(root1->right,path1);
    }
    void getlefaDataRoot2(TreeNode* root2,vector<int> &path2){
        if(root2==nullptr) return ;
       if(root2->left==NULL && root2->right==NULL){
            path2.push_back(root2->val);
        }
        getlefaDataRoot1(root2->left,path2);
        getlefaDataRoot1(root2->right,path2);
    }
    bool GetSolution(vector<int> &path1,vector<int> &path2){
        if(path1.size()>path2.size()) return 0;
        for(int i=0; i<path2.size(); i++){
            if(path2[i] != path1[i]){
                return 0;
            }
        }
        return 1;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2 == NULL ) return 1;
        vector<int> path1;
        vector<int> path2;
        getlefaDataRoot1(root1,path1);
        getlefaDataRoot2(root2,path2);
        return GetSolution(path1,path2);
    }
};
// @lc code=end

