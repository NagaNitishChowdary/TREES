// PROBLEM LINK --- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

#include<bits/stdc++.h>
using namespace std ;

struct TreeNode{
    int data ;
    TreeNode *left,*right ;
    TreeNode(int val){
        data = val ;
        left = right = NULL ;
    }
};

void preorderTraversal(TreeNode *root){
    if(root == NULL) return ;
    cout << root -> data << " " ;
    preorderTraversal(root -> left) ;
    preorderTraversal(root -> right) ;
}

TreeNode *buildTree1(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart,int postEnd,map<int,int> &mpp){
    if(inStart > inEnd || postStart > postEnd) return NULL ;
    TreeNode *root = new TreeNode(postorder[postEnd]) ;
    int inRoot = mpp[postorder[postEnd]] ;
    int numsLeft = inRoot - inStart ;
    root -> left = buildTree1(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,mpp) ;
    root -> right = buildTree1(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,mpp) ;
    return root ;
}

TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder) {
    // STORE THE VALUES OF INORDER IN MAP
    map<int,int> mpp ;
    int size = inorder.size() ;
    for(int i=0 ; i<size ; i++) mpp[inorder[i]] = i ;
    TreeNode *root = buildTree1(inorder,0,size-1,postorder,0,size-1,mpp);
    return root ;
}


int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> inorder(n) ;
        for(int i=0 ; i<n ; i++) cin >> inorder[i] ;
        vector<int> postorder(n) ;
        for(int i=0 ; i<n ; i++) cin >> postorder[i] ;
         TreeNode *root = buildTree1(inorder,postorder) ;
         preorderTraversal(root) ;
    }
    return 0 ; 
}
