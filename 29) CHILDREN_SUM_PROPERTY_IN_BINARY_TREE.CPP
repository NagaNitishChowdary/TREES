// PROBLEM LINK --- https://leetcode.com/problems/root-equals-sum-of-children/description/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/children-sum-parent/1

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

void inorder(node *root){
    if(root == NULL) return ;
    inorder(root -> left) ;
    cout << root -> data << " " ;
    inorder(root -> right) ;
}

void levelorder(node *root){
    if(root == NULL) return ;
    vector<vector<int >> ans ;
    queue<node*> q ;
    q.push(root) ;
    while(!q.empty()){
        int size = q.size() ;
        vector<int> level ;
        for(int i=0 ; i<size ; i++){
            node *knnc = q.front() ;
            q.pop() ;
            if(knnc -> left) q.push(knnc->left) ;
            if(knnc -> right) q.push(knnc->right) ;
            level.emplace_back(knnc->data) ;
        }
        ans.emplace_back(level) ;
    }
    for(auto vctr:ans){
        for(auto it:vctr) cout << it << " " ;
        cout << endl ;
    }
}

/*

//
void childrenSumProperty(node *root){ 
    // cout << "hi" << " " ;
    if(root == NULL) return ; 
    int child = 0 ; 
    if(root -> left != NULL) child += root -> left -> data ; 
    if(root -> right != NULL) child += root -> right -> data ; 
    if(child < root -> data){ 
        if(root -> left) root -> left -> data = root -> data ; 
        if(root -> right) root -> right -> data = root -> data ; 
    } 
    else{ 
        root -> data = child ; 
    } 

    childrenSumProperty(root -> left) ; 
    childrenSumProperty(root -> right) ; 

    int parent=0 ; 
    if(root -> left != NULL) parent += root -> left -> data ; 
    if(root -> right != NULL) parent += root -> right -> data ; 
    if(root -> left or root -> right) root -> data = parent ; 
}

int main()
{
    node *root = new node(40) ;
    root -> left = new node(10) ;
    root -> right = new node(20) ;
    root -> left -> left = new node(2) ;
    root -> left -> right = new node(5) ;
    root -> right -> left = new node(30) ;
    root -> right -> right = new node(40) ;
    childrenSumProperty(root) ;
    levelorder(root) ;

    return 0 ; 
} 

*/

bool checkTree(node* root) {
    if(root == NULL) return 1 ;
    int child = 0 ;
    if(root -> left) child += root -> left -> data ;
    if(root -> right) child += root -> right -> data ;
    if(root -> left == NULL && root -> right == NULL ) return 1 ;
    if(root -> data != child) return 0 ;
    //else return 1 ;

    if(root -> left) if(checkTree(root -> left) == 0) return 0 ;
    if(root -> right) if(checkTree(root -> right) == 0) return 0 ;
    return 1 ;
}


int main()
{
    node *root = new node(5) ;
    root -> left = new node(4) ;
    root -> right = new node(1) ;
    cout << checkTree(root) << endl ;
    return 0 ; 
}

