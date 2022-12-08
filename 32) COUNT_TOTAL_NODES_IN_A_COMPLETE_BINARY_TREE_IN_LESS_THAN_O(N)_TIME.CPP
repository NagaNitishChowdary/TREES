// PROBLEM LINK --- https://leetcode.com/problems/count-complete-tree-nodes/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/count-complete-binary-tree-nodes_982774

// WE CAN EASILY DO IT WITH INORDER (OR) PREORDER (OR) POSTORDER (OR) LEVELORDER TRAVERSAL WITH O(N) TIME  

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

int findLeftHeight(TreeNode *root){
    int height = 0 ;
    while(root){
        height++ ;
        root = root -> left ;
    }
    return height ;
}

int findRightHeight(TreeNode *root){
    int height = 0 ;
    while(root){
        height++ ;
        root = root -> right ;
    }
    return height ;
}

int countNodes(TreeNode* root) {
    if(root == NULL) return 0 ;
    
    int leftHeight = findLeftHeight(root) ;
    int rightHeight = findRightHeight(root) ;
    
    if(leftHeight == rightHeight) return (1<<leftHeight) - 1 ; // IF LEFT AND RIGHT HEIGHTS EQUAL THEN THERE ARE 2 POWER N -1 NODES IN IT 
    return 1 + countNodes(root->left) + countNodes(root->right) ;
}

int main()
{
    TreeNode *root = new TreeNode(1) ;
    root -> left = new TreeNode(2) ;
    root -> right = new TreeNode(3) ;
    root -> left -> left = new TreeNode(4) ;
    root -> left -> right = new TreeNode(5) ;
    root -> right -> left = new TreeNode(6) ;

    cout << countNodes(root) << "\n" ;
    return 0 ; 
}
