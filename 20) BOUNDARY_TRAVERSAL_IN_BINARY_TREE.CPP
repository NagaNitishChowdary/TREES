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

bool isLeaf(node *h){
    if(h->left == NULL && h->right == NULL) return true;
    else return false ;
}

void addLeftBoundary(node *root,vector<int> &res){
    node *curr = root -> left ;
    while(curr){
        if(!isLeaf(curr)) res.emplace_back(curr -> data) ;
        if(curr -> left) curr = curr -> left ;
        else curr = curr -> right ;
    }
}

void addLeaves(node *root,vector<int> &res){
    if(isLeaf(root)){
        res.emplace_back(root -> data) ;
        return ;
    }
    if(root -> left) addLeaves(root->left,res) ;
    if(root -> right) addLeaves(root->right,res) ;
}

void addRightBoundary(node *root,vector<int> &res){
    node *curr = root -> right ;
    vector<int> temp ;
    while(curr){
        if(!isLeaf(curr)) temp.emplace_back(curr->data) ;
        if(curr -> right) curr = curr->right ;
        else curr = curr -> left ;
    }
    for(int i=temp.size()-1 ; i>=0 ; i--){
        res.emplace_back(temp[i]) ;
    }
}

vector<int> printBoundary(node *root){
    vector<int> res ;
    if(root == NULL) return res ;
    if(!isLeaf(root)) res.emplace_back(root -> data) ;
    addLeftBoundary(root,res) ;
    addLeaves(root,res) ;
    addRightBoundary(root,res) ;
    return res ;
}

int main()
{
    node* root = new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    root->right = new node(22);
    root->right->right = new node(25);
    vector<int> knnc = printBoundary(root) ;
    for(auto it:knnc) cout << it << " " ;
    cout << endl ;
    return 0;
}
