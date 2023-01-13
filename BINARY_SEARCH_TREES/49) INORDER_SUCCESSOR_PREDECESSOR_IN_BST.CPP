// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/predecessor-and-successor_920476
// PROBLEM LINK --- https://leetcode.com/problems/inorder-successor-in-bst/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

#include<bits/stdc++.h>
using namespace std ;

class binaryTreeNode{

public :
    int data ;
    binaryTreeNode* left ;
    binaryTreeNode* right;

    binaryTreeNode(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

vector<int> findPreSuc(binaryTreeNode *root, int key)
{
    // Write your code here.
    vector<int> ans ;
    int successor = -1 , predecessor = -1 ;
    binaryTreeNode *dup1 = root , *dup2 = root ;
    while(dup1 != NULL){
        if(key >= dup1->data) dup1 = dup1 -> right ;
        else{
            successor = dup1 -> data ;
            dup1 = dup1 -> left ;
        }
    }
    
    while(dup2 != NULL){
        if(key <= dup2 -> data) dup2 = dup2 -> left ;
        else{
            predecessor = dup2 -> data ;
            dup2 = dup2 -> right ;
        }
    }
    
    ans.emplace_back(predecessor) ;
    ans.emplace_back(successor) ;
    return ans ;
}

int main()
{
    binaryTreeNode *root = new binaryTreeNode(2) ;
    root -> left = new binaryTreeNode(1) ;
    root -> right = new binaryTreeNode(3) ;
    vector<int> ans = findPreSuc(root , 2) ;
    for(auto it:ans) cout << it << " " ; cout << endl ;
    return 0 ; 
}
