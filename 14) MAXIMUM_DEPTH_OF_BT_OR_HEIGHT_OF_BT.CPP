// CAN BE DONE IN 2 WAYS 
// USING LEVEL ORDER TRAVERSAL
// USING RECURSION

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
    int maxDepth(TreeNode* root) {
    
    // LEVEL ORDER TRAVERSAL
    /*
    // vector<vector<int>> ans ;
    int knnc = 0 ;
    if(root == NULL) return knnc ;
    queue< TreeNode* > q ;
    q.push(root) ;
    while(!q.empty()){
        //vector<int> level ;
        int size = q.size() ;
        for(int i=0 ; i<size ; i++){
            TreeNode *n = q.front() ;
            q.pop() ;
            if(n -> left != NULL) q.push(n -> left) ;
            if(n -> right != NULL) q.push(n -> right) ;
            //level.emplace_back(n -> val) ;
        }
        //ans.emplace_back(level) ;
        knnc++ ;
    }
    return knnc ;
    */

    // RECURSION
    if(root == NULL) return 0 ;
    int left = maxDepth(root -> left) ;
    int right = maxDepth(root -> right) ;
    return 1 + max(left,right) ;
    }
};
