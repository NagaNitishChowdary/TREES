// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/delete-node-in-bst_920381?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
// PROBLEM LINK --- https://leetcode.com/problems/delete-node-in-a-bst/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

#include<bits/stdc++.h>
using namespace std ;

struct Node{
    int data ;
    Node *left , *right ;
    Node(int val){
        data = val ;
        left = right = NULL ;
    }
} ; 

Node *findLastRight(Node *root){
    if(root -> right == NULL) return root ;
    return findLastRight(root -> right) ;
}

Node *helper(Node *root){
    if(root -> left == NULL) return root -> right ;
    else if(root -> right == NULL) return root -> left ;
    Node *rightChild = root -> right ;
    Node *lastRight = findLastRight(root -> left) ;
    lastRight -> right = rightChild ;
    return root -> left ;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root == NULL) return root ;
    if(root -> data == X) return helper(root) ;
    Node *dummy = root ;
    while(root != NULL){
        if(root -> data > X){
            if(root -> left != NULL && root -> left -> data == X){
                root -> left = helper(root -> left) ;
                break ;
            } 
            else root = root -> left ;
        } else {
            if(root -> right != NULL && root -> right -> data == X){
                root -> right = helper(root -> right) ;
                break ;
            }
            else root = root -> right ;
        }
    }
    return dummy ;
}

void inorder(Node *root){
    if(root == NULL) return ;
    inorder(root -> left) ;
    cout << root -> data << " " ;
    inorder(root -> right) ;
}

int main() {
    Node *root = new Node(2) ;
    root -> left = new Node(1) ;
    root -> right = new Node(3) ;
    inorder(root) ; cout << endl ;
    Node *knnc = deleteNode(root,2) ;
    inorder(knnc) ; cout << endl ;
    return 0;
}
