// LEETCODE PROBLEM LINK --- https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

    void preorder(TreeNode *root,vector<int> &ans){
        if(root == NULL) return ;
        ans.emplace_back(root -> val) ;
        preorder(root -> left , ans) ;
        preorder(root -> right , ans ) ;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        /*
        vector<int> ans ;
        if(root == NULL) return ans ;
        stack< TreeNode* > s;
        s.push(root) ;
        while(!s.empty()){
            TreeNode *n = s.top() ;
            ans.emplace_back(n -> val) ;
            s.pop() ;
            if(n -> right != NULL) s.push(n -> right) ;
            if(n -> left != NULL) s.push(n -> left) ;
        }
        return ans ;
        */
        vector<int> ans ;
        preorder(root,ans) ;
        return ans ;
    }
};
