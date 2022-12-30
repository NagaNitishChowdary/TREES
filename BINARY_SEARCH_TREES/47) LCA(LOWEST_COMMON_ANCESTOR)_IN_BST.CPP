// PROBLEM LINK --- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

#include <bits/stdc++.h> 
using namespace std ;

struct node{
    int data ;
    node *left,*right ;
    node(int val){
        data = val ;
        left = right = NULL ;
    }
};

node *LCAinaBST(node *root, node *P, node *Q)
{
    // Write your code here
    if(root == NULL) return root ;
    // IF BOTH P AND Q LIE ON THE RIGHT SIDE OF THE NODE 
    if(P -> data > root -> data && Q -> data > root -> data){
        return LCAinaBST(root -> right , P , Q) ;
    }
    // IF BOTH P AND Q LIE ON THE LEFT SIDE OF THE NODE 
    if(P -> data < root -> data && Q -> data < root -> data){
        return LCAinaBST(root -> left , P , Q) ;
    }
    // OR ELSE IT IS ONE OF THE NODE 
    return root ;
}

int main()
{
    node *root = new node(2) ;
    root -> left = new node(1) ;
    root -> right = new node(4) ;
    cout << LCAinaBST(root , root -> left ,root -> right) -> data << endl ;
    return 0 ; 
}
