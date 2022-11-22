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

// (node,num) 
// if num = 1
// preorder
// ++
// left

// if num = 2
// inorder
// ++ 
// right 

// if num = 3
// postorder

class Solution {
public:
    vector<int> preInPostTraversal(TreeNode *root){
        stack< pair<TreeNode*,int> > st ;
        st.push({root,1}) ;
        vector<int> preorder , inorder , postorder ;
        if(root == NULL) return ;
        while(!st.empty()){
            auto it:st.top() ;
            st.pop() ;

            // THIS IS THE FIRST PART OF THE PREORDER
            // INCREMENT 1 TO 2
            // PUSH THE LEFT SIDE OF THE TREE
            if(it.second == 1){
                preorder.emplace_back(it.first -> val) ;
                it.second++ ;
                st.push(it) ;

                if(it.first->left != NULL) st.push({it.first->left,1}) ;
            }

            // THIS IS THE SECOND PART OF INORDER
            // INCREMENT 2 TO 3
            // PUSH RIGHT
            else if(it.second == 2){
                inorder.emplace_back(it.first -> val) ;
                it.second++ ;
                st.push(it) ;

                if(it.first -> right != NULL) st.push({it.first->right,1});
            }

            // DONT PUSH IT BACK AGAIN
            else postorder.emplace_back(it.first->val) ;
        }
    }
};
