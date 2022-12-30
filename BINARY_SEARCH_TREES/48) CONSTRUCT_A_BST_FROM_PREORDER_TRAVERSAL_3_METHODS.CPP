// PROBLEM LINK --- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/bst-from-preorder_2689307
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

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

node *build(vector<int> &preOrder , int &i , int bound){
        if(i == preOrder.size() || preOrder[i] > bound) return NULL ;
        node *root = new node(preOrder[i++]) ;
        root -> left = build(preOrder , i , root -> data) ;
        root -> right = build(preOrder , i , bound) ;
        return root ;
}

node* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i=0 ;
    return build(preOrder,i,INT_MAX) ;
}

void inorder(node *h){
    if( h == NULL) return ;
    inorder(h -> left) ;
    cout << h -> data << " " ;
    inorder(h -> right) ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
    int n ; cin >> n ;
    vector<int> preOrder(n) ;
    for(int i=0 ; i<n ; i++) cin >> preOrder[i] ;
    node *knnc = preOrderTree(preOrder) ;
    inorder(knnc) ; cout << endl ;
}
    return 0 ; 
}
