// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/insert-into-a-binary-search-tree_1279913?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1
// PROBLEM LINK --- https://leetcode.com/problems/insert-into-a-binary-search-tree/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

#include<bits/stdc++.h>
using namespace std ;

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(TreeNode<int> *h){
    if(h == NULL) return ;
    cout << h -> val << " " ;
    preorder(h -> left) ;
    preorder(h -> right) ;
}

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Write your code here.
    if(root == NULL) return new TreeNode<int>(val) ;
    TreeNode<int> *curr = root ;
    while(true){
        if(curr -> val <= val){
            if(curr -> right == NULL){
                curr -> right = new TreeNode<int>(val) ;
                break ;
            }
            else curr = curr -> right ;
        }
        else
        {
            if(curr -> left == NULL){
                curr -> left = new TreeNode<int>(val) ;
                break ;
            }
            else curr = curr -> left ;
        }
    }
    return root ;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(10) ;
    root -> left = new TreeNode<int>(8) ;
    root -> right = new TreeNode<int>(12) ;
    preorder(root) ; cout << endl ;
    TreeNode<int> *knnc = insertionInBST(root , 15) ;
    preorder(knnc) ; cout << endl ;
    return 0 ; 
}
