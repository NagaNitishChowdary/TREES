// PROBLEM LINK --- https://leetcode.com/problems/validate-binary-search-tree/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/check-for-bst/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/validate-bst_981275?leftPanelTab=0

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

bool isValid(node *root , long long int minVal , long long int maxVal){
        if(root == NULL) return true ;
        if(root -> data >= maxVal || root -> data <= minVal) return false ;
        return isValid(root -> left , minVal , root -> data) && isValid(root -> right , root ->data , maxVal) ;
}

bool validateBST(node *root) 
{
    // Write your code here
    return isValid(root , LONG_MIN , LONG_MAX) ;
}

int main()
{
    node *root = new node(2) ;
    root -> left = new node(1) ;
    root -> right = new node(4) ;
    cout << validateBST(root) << endl ;
    return 0 ; 
}
