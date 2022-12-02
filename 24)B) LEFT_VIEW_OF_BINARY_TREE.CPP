// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

// TIME COMPLEXITY --- O(N) 

// USING RECURSIVE PREORDER TRAVERSAL
void leftView(node *root , int level , vector<int> &ans2){
    if(root == NULL) return ;
    if(level == ans2.size()) ans2.emplace_back(root->data) ;
    leftView(root->left,level+1,ans2) ;
    leftView(root->right,level+1,ans2) ;
}

vector<int> leftSideView(node* root){
    vector<int> ans2 ;
    leftView(root,0,ans2) ;
    return ans2 ;
}

// USING LEVEL ORDER TRAVERSAL
/*
vector<int> leftView(node *root){
    vector<int> ans ;
    queue< node* > q ;
    if(root == NULL) return ans ;
    q.push(root) ;
    while(!q.empty()){
        int size = q.size() ;
        vector<int> level ;
        for(int i=0 ; i<size ; i++){
            node *knnc = q.front() ;
            q.pop() ;
            if(knnc->left != NULL) q.push(knnc->left) ;
            if(knnc->right != NULL) q.push(knnc->right) ;
            level.emplace_back(knnc->data) ;
        }
        ans.emplace_back(level.front()) ;
    }
    return ans ;
}
*/

int main()
{
    node *root = new node(1) ;
    root -> left = new node(2) ;
    root -> right = new node(3) ;
    root -> left -> left = new node(4) ;
    root -> left -> right = new node(5) ;
    root -> left -> right -> left = new node(6) ;
    root -> right -> right = new node(7) ;

    vector<int> right = rightSideView(root) ;
    vector<int> left = leftSideView(root) ;

    cout << "RIGHT VIEW " << endl ;
    for(auto it:right) cout << it << " " ;
    cout << endl ;
 
    cout << "LEFT VIEW" << endl ;
    for(auto it:left) cout << it << " " ;
    cout << endl ;

    return 0 ;
}
