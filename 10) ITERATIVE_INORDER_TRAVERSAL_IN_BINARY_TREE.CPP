// LEETCODE LINK --- https://leetcode.com/problems/binary-tree-inorder-traversal/description/


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

    void inorder(TreeNode *root,vector<int> &knnc){
        if(root == NULL) return ;
        inorder(root -> left , knnc ) ;
        knnc.emplace_back(root -> val) ;
        inorder(root -> right , knnc) ;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        /*
        vector<int>knnc;
        inorder(root,knnc) ;
        return knnc ;
        */

        vector<int>inorder ;
        stack< TreeNode* > s ;
        TreeNode *node = root ;
        while(true){
            if(node != NULL){
                s.push(node) ;
                node = node -> left ;
            }
            else{
                if(s.empty() == true) break ;
                node = s.top() ;
                s.pop() ;
                inorder.emplace_back(node -> val) ;
                node = node -> right ;
            }
        }
        return inorder ;

    }
};
