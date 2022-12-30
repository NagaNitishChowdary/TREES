// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333
// PROBLEM LINK --- https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data ;
    node *left,*right ;
    node(int val){
        data = val ;
        left = right = NULL ;
    }
};


void inorder1(node *root,int k,int cnt ,vector<int> &inorder){
    if(root == NULL) return ;
    if(cnt == k) return ;
    inorder1(root -> left ,k,cnt, inorder) ;
    inorder.emplace_back(root -> data) ; cnt++ ;
    inorder1(root -> right ,k,cnt, inorder) ;
}

int kthSmallest(node* root, int k) {
    // Write your code here.
    vector<int> inorder ;
    inorder1(root , k , 0 ,inorder) ;
    if(inorder.size() < k) return -1 ;
    return inorder[k-1] ;
    // return inorder.back() ;
}

int main()
{
    node *root = new node(20) ;
    root -> left = new node(10) ;
    root -> right = new node(30) ;
    cout << kthSmallest(root , 1) << endl ;
    return 0 ; 
}
