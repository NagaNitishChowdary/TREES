#include<bits/stdc++.h>
using namespace std;

struct node{
    int data ;
    struct node *left ;
    struct node *right ;
    node(int x){
        data = x ;
        left = right = NULL ;
    }
};

void preorder(node *root){
    if(root == NULL) return ;
    cout << root -> data << " " ;
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(node *root){
    if(root == NULL) return ;
    inorder(root -> left) ;
    cout << root -> data << " ";
    inorder(root -> right) ;
}

void postorder(node *root){
    if(root == NULL) return ;
    postorder(root -> left) ;
    postorder(root -> right) ;
    cout << root -> data << " ";
}

int main()
{
    struct node *root = new node(1);
    root -> left = new node(2) ;
    root -> right = new node(3) ;
    root -> left -> right = new node(4) ;
    inorder(root); 
    cout << endl ;
    preorder(root);
    cout << endl ;
    postorder(root);
}

// TREE

//     1
//  2     3
//    4
