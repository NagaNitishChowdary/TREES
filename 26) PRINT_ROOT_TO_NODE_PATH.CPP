#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data ;
    node *left , *right ;
    node(int val){
        data = val ;
        left = right = NULL ;
    }
} ;


bool getPath(node *root,int x,vector<int> &arr){
    if(root == NULL) return false ;
    arr.emplace_back(root ->data) ;
    if(root -> data == x) return true ;
    if(getPath(root->left,x,arr) || getPath(root->right,x,arr)) return true ;
    arr.pop_back() ;
    return false ;
}

vector<int> solve(node *root,int x){
    vector<int> arr ;
    getPath(root,x,arr) ;
    return arr ;
}

int main()
{
    node *root = new node(1) ;
    root -> left = new node(2) ;
    root -> right = new node(3) ;
    root -> left -> left = new node(4) ;
    root -> left -> right = new node(5) ;
    root -> left -> right -> left = new node(6) ;
    root -> left -> right -> right = new node(7) ;
    int x ; cin >> x ;
    vector<int> ans = solve(root,x) ;
    for(auto it:ans) cout << it << " " ; cout << endl ; 

    return 0 ;
}
