// PROBLEM LINK --- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/854031713/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data ;
    node *left , *right ;
    node(int val){
        data = val ;
        left = right = NULL ;
    }
};

node* lowestCommonAncestor(node* root, node* p, node* q) {

    if(root == NULL || p == root || root == q) return root ;
    node *left = lowestCommonAncestor(root->left,p,q) ;
    node *right = lowestCommonAncestor(root->right,p,q) ;
    if(left == NULL) return right ;
    else if(right == NULL) return left ;
    else return root ;
}

int main()
{
    node *root = new node(1) ;
    root -> left = new node(2) ;
    root -> right = new node(3) ;
    root -> left -> left = new node(4) ;
    root -> right -> right = new node(9) ;
    root -> left -> right = new node(5) ;
    root -> left -> right -> left = new node(6) ;
    root -> left -> right -> right = new node(7) ;
    root -> right -> left = new node(8) ; 

    // LCS(4,7) = 2 
    cout << lowestCommonAncestor(root,root -> left -> left,root -> left -> right -> right)->data << endl ;
    // LCS(5,9) = 1
    cout << lowestCommonAncestor(root,root -> left -> right,root -> right -> right)->data << endl ;
    // LCS(2,6) = 2
    cout << lowestCommonAncestor(root,root->left,root -> left -> right -> left)->data << endl ;

    return 0 ;
}

