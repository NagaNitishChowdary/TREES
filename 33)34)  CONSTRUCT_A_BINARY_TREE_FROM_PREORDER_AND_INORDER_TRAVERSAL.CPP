// PROBLEM LINK --- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/construct-tree-1/1

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

void inorderTraversal(TreeNode *root){
    if(root == NULL) return ;
    inorderTraversal(root -> left) ;
    cout << root -> data << " " ;
    inorderTraversal(root -> right) ;
}

TreeNode *buildTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &mpp){
    if(preStart > preEnd || inStart > inEnd) return NULL ;
    TreeNode *root = new TreeNode(preorder[preStart]) ;
    // FINDING THE ROOT VAL IN INORDER VECTOR
    int inRoot = mpp[root -> data] ;
    int numsLeft = inRoot - inStart ;
    root -> left = buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mpp) ;
    root -> right = buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mpp) ;
    return root ;
}

TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
    // USE MAP FOR STORING INORDER VALUES
    // SO NOT TO CHECK FOR EACH TAKING OF PREORDER VALUES
    map<int,int> mpp ;
    int size = inorder.size() ;
    for(int i=0 ; i<size ; i++) mpp[inorder[i]] = i ;
    // CONSTRUCT A TREE
    TreeNode *root = buildTree(preorder,0,size-1,inorder,0,size-1,mpp) ; 
    return root ;
    //inorder(root) ;
}


int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> preorder(n) ;
        for(int i=0 ; i<n ; i++) cin >> preorder[i] ;
        vector<int> inorder(n) ;
        for(int i=0 ; i<n ; i++) cin >> inorder[i] ;
         TreeNode *root = buildTree1(preorder,inorder) ;
         inorderTraversal(root) ;
    }
    return 0 ; 
}
