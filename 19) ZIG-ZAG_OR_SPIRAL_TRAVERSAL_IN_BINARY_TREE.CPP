// PROBLEM LINK --- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// INTUTION BEHIND THIS IS NOTHING BUT LEVEL ORDER TRAVERSAL BUT FIRST IT GOES TO LEFT TO RIGHT AND THEN RIGHT TO LEFT AND SO ON
// CONSIDER INITIALLY FLAG AS TRUE AND FOR EVERY ONE LEVEL CHANGE FLAG VALUE 
// IF FLAG VALUE IS TRUE APPEND IT LEFT TO RIGHT ELSE RIGHT TO LEFT 

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        if(root == NULL) return ans ;
        queue< TreeNode* > q ;
        q.push(root) ;
        bool flag = true ;
        while(!q.empty()){
            vector<int>level ;
            int size = q.size() ;
            for(int i=0 ; i<size ; i++){
                TreeNode *node = q.front() ;
                q.pop() ;
                if(node->left != NULL) q.push(node -> left) ;
                if(node->right != NULL) q.push(node -> right) ;
                level.emplace_back(node -> val);
            }
            if(flag){ ans.emplace_back(level) ; flag = false ; }
            else{
                reverse(level.begin(),level.end()) ;
                ans.emplace_back(level) ;
                flag = true ;
            }
        }
        return ans ;
    }
};
