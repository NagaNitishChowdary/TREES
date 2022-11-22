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

    void postorder(TreeNode *root,vector<int> &knnc){
        if(root == NULL) return ;
        postorder(root -> left,knnc);
        postorder(root -> right,knnc) ;
        knnc.emplace_back(root -> val) ;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        /*
        // RECURSION
        vector<int> knnc ;
        postorder(root,knnc) ;
        return knnc;
        */

        // ITERATIVE POSTORDER TRAVERSAL
        /*
        stack < TreeNode* > s1,s2 ;
        vector<int> postorder ;
        if(root == NULL) return postorder ;
        s1.push(root) ;
        while(!s1.empty()){
            root = s1.top() ;
            s1.pop() ;
            s2.push(root) ;
            if(root -> left != NULL) s1.push(root -> left) ;
            if(root -> right != NULL) s1.push(root -> right) ;
        }
        while(!s2.empty()){ postorder.emplace_back(s2.top() -> val);
        s2.pop(); }
        return postorder ;
        */

        // ITERATIVE POSTORDER TRAVERSAL USING 1 STACK
        vector<int> postorder ;
        if(root == NULL) return postorder ;
        stack < TreeNode* > s ;
        s.push(root) ;
        TreeNode *node;
        while(!s.empty()){
            node = s.top() ;
            s.pop();
            if(node -> left != NULL) s.push(node -> left) ;
            if(node -> right != NULL) s.push(node -> right) ;
            postorder.emplace_back(node -> val) ;
        }
        reverse(postorder.begin(),postorder.end());
        return postorder ;
    }


};
