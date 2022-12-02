// PROBLEM LINK --- https://leetcode.com/problems/symmetric-tree/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data ;
    node *left,*right ;
    node(int val){
        data = val ;
        left = right = NULL ;
    }
};

bool isSymmetric(node *left,node *right){
    if(left == NULL || right == NULL) return left == right ;
    if(left -> data != right->data ) return false ;
    return isSymmetric(left->left ,right -> right) && isSymmetric(left->right,right->left) ;
}

bool symmetric(node *root){
    return root == NULL || isSymmetric(root -> left , root -> right) ;
}

int main() {
    node *root  = new node(1) ;
    root -> left = new node(2)  ;
    root -> right = new node(2) ;
    root -> left -> left = new node(3) ;
    root -> right -> right = new node(3) ;
    cout << symmetric(root) << endl ;
    return 0 ;

}
