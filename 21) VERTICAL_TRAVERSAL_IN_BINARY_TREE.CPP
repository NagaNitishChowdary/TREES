// PROBLEM LINK --- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

vector<vector<int>> verticalTraversal(node *root){
    map<int,map<int,multiset<int>>> nodes ;
    queue<pair<node*,pair<int,int>>> todo ;
    todo.push({root,{0,0}}) ;
    while(!todo.empty()){
        auto p = todo.front() ;
        todo.pop() ;
        node *n = p.first ;
        int x = p.second.first , y = p.second.second ;
        nodes[x][y].insert(n->data) ;
        if(n->left) todo.push({n->left,{x-1,y+1}}) ;
        if(n->right) todo.push({n->right,{x+1,y+1}}) ;
    }
    vector<vector<int>> ans ;
    for(auto p:nodes){
        vector<int> col ;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end()) ;
        }
        ans.emplace_back(col) ;
    }
    return ans ;
}

int main()
{
    node* root = new node(1) ;
    root->left = new node(2) ;
    root->right = new node(3) ;
    root -> left -> left = new node(4) ;
    root -> left ->left -> right = new node(5) ;
    root -> left -> left -> right -> right = new node(6) ;
    root -> left -> right = new node(10) ;
    root -> right -> left = new node(9) ;
    root -> right -> right = new node(10) ;
    vector<vector<int>> knnc = verticalTraversal(root) ;
    for(auto vctr:knnc){
        for(auto it:vctr) cout << it << " " ;
        cout << endl ;
    }

    return 0;
}
